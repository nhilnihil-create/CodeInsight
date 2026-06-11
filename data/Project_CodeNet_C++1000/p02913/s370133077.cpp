#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
string S;
int ans=0;
void solve(){
    vector<int> Z(S.size());
    Z[0] = S.size();
    int i = 1, j = 0;
    while(i < S.size()){
        while(i + j < S.size() && S[j] == S[i + j]) j++;
        Z[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(k < j && k + Z[k] < j){
            Z[i + k] = Z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    rep(i,S.size()-1) if(Z[i+1]<=i+1) ans=max(ans,Z[i+1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin>>n>>s;
    rep(i,n){
        S.clear();
        S=s.substr(i,n-i);
        solve();
    }
    cout<<ans;
}