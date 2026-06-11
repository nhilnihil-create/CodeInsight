#include <bits/stdc++.h>
#define ll long long
#define V vector<long long>
#define VV vector<vector<long long>>
#define VVV vector<vector<vector<long long>>>
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

int main() {
    ll n,k,c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    ll cnt=0;
    V r;
    rep(i,n){
        if(s[n-1-i]=='o'){
            cnt++;
            r.push_back(n-1-i);
            i+=c;
        }
    }
    if(cnt==k){
        V l(k,0);
        reverse(r.begin(), r.end());
        ll pos=0;
        rep(i,n){
            if(s[i]=='o'){
                l[pos]=i;
                pos++;
                i+=c;
            }
        }
        rep(i,k){
            if(l[i]==r[i]){
                cout<<l[i]+1<<endl;
            }
        }
    }
}
