// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
int dig(int n){
    int cnt = 0;
    if(n == 0)
        cnt = 1;
    while(n){
        ++cnt;
        n /= 10;
    }
    return cnt;
}
void solve(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> vec(m);
    for(int i = 0; i < m; i++)
        cin>>vec[i].first>>vec[i].second;
    for(int i = 0; i < 1000; i++){
        bool f = true;
        for(auto itr : vec){
            int digit = i/pow(10, n-itr.first);
            digit %= 10;
            if(digit != itr.second){
                f = false;
                break;
            }
        }
        if(f && dig(i)==n){
            cout<<i;
            return ;
        }
    }
    cout<<"-1";
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}