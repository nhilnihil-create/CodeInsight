#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;

int main(){
    int n, x;
    cin >> n >> x;
    int dis = 0;
    int count = 0;
    vector<int> l(n);
    for(int i = 0; i < n; i++){
        cin >> l.at(i);
    }
    for(int i = 0; i < n; i++){
        dis += l.at(i);
        if(dis <= x) count++;
    }
    cout << count + 1 << endl;
    return 0;
}