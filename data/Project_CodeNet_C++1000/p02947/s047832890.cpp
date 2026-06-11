
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    map<string,int> mp;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        sort(all(s));
        mp[s] ++;
    }
    ll ans=0;
    for(auto &x:mp){
        int a = x.second;
        ans +=(ll)a*(a-1)/2;
    }
    cout << ans << endl;

}