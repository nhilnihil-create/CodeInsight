#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    string s;
    cin>>s;
    int n=s.size();
    vin ama(n+1,0);
    vll cnt(2019,0);
    vin ten(n+1,1);
    rep(i,n){
        ten[i+1]=ten[i]*10;
        ten[i+1]%=2019;
    }
    rep(i,n){
        ama[i+1]=ama[i]+(s[n-i-1]-'0')*ten[i+1];
        ama[i+1]%=2019;
        cnt[ama[i+1]]++;
    }
    cnt[0]++;
    ll ans=0;
    rep(i,2019){
        ans+=(cnt[i]-1)*cnt[i]/2;
    }
    cout<<ans<<endl;
    
    
    
    
  

}
