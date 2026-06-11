#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v1, v2;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if(n % 2 == 1){
        cout << v2[n/2] - v1[n/2] + 1;
    }
    else{
        cout << v2[n/2 - 1] + v2[n/2] - v1[n/2 - 1] - v1[n/2] + 1;
    }
    return 0;
}