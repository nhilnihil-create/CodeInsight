#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;


ll n;
typedef pair<ll,ll> pll;
vector< pll > ans;
void makeit(ll X)
{
        for(ll i=2;i<=X;i++){
                ans.pb(make_pair(i,i-1));
        }
        ans.pb(make_pair(X, n+1));
        for(ll i=2;i<=X;i++){
                ans.pb(make_pair(n+i,n+i-1));
        }
}
void pints()
{
        cout << "Yes\n";
        for(auto &i:ans){
                cout << i.first << " " << i.second << "\n";
        }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        ll pw = 1LL;
        set<ll> S;
        S.insert(pw);
        while(pw <= 100000){
                pw *= 2LL;
                S.insert(pw);
        }
        cin >> n;
        if(S.find(n) != S.end()){
                cout << "No\n"; return 0;
        }
        if(n%4 == 3){
                makeit(n);
                pints();
                return 0;
        }else if(n%4 == 1) {
                makeit(n-2);
                ans.pb(make_pair(1LL , n));
                ans.pb(make_pair(n, n-1));
                ans.pb(make_pair(1LL , n+n-1));
                ans.pb(make_pair(n+n-1, n+n));
                pints();
                return 0;
        }else if(n%4 == 2) {
                makeit(n-3);
                ans.pb(make_pair(1LL , n-1));
                ans.pb(make_pair(n-1, n-2));
                ans.pb(make_pair(1LL , n+n-2));
                ans.pb(make_pair(n+n-2, n+n-1));
                ans.pb(make_pair(n-1, n));
                ans.pb(make_pair(2LL , n+n));
                pints(); return 0;
        }else {
                makeit(n-1);
                ll yo = n-1;
                ll reqq = yo ^ n;
                ans.pb(make_pair(yo, n));
                ans.pb(make_pair(n+reqq-1, n+n));
                pints();
                return 0;
        }
        return 0;
}
