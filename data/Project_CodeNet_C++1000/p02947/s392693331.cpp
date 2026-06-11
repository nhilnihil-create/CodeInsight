#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    unordered_map<string,long> u;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        sort(a.begin(),a.end());
        u[a]++;
    }
    long ans = 0;
    for(auto x:u){
        long y = x.second;
        ans += y*(y-1)/2;
    }
    cout << ans << endl;
}
