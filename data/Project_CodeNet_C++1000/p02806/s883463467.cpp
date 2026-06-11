#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    int n;cin >>n;
    vector<string>s(n);
    V t(n);
    for (int i = 0; i < n; ++i) {
        cin >>s[i]>>t[i];
    }
    string x;cin >>x;
    int ans=0;
    bool flg=false;
    for (int i = 0; i < n; ++i) {
        if(flg)ans+=t[i];
        if(s[i]==x)flg=true;
    }
    cout <<ans <<endl;
}
