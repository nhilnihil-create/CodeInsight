#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int N,M;
    cin >> N >> M;
    vector<int>v;
    int sum = 0;
    while(N--){
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    double low = (double)sum /(4 * M);
    sort(v.rbegin(),v.rend());
    for(int i = 0;i < M;i++){
        if(v[i] < low){
            cout << "No" <<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
