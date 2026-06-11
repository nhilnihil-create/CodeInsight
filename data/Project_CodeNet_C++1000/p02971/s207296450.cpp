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
    V a(n);
    V c(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        c[i]=a[i];
    }
    sort(all(c));
    int mx=c.back();
    int se=c[n-2];
    for (int i = 0; i < n; ++i) {
        if(a[i]==mx)cout <<se<<endl;
        else cout <<mx<<endl;
    }
}

