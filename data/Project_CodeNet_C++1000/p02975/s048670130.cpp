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

int main() {
   int n;cin >>n;
   vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    sort(all(a));
    bool flg=true;
    if(a.back()==0){
        puts("Yes");
        return 0;
    }
    if(a.size()%3!=0){
        flg=false;
    }
    int m=a.size()/3;
    if(a[0]!=a[m-1])flg=false;
    if(a[m]!=a[2*m-1])flg=false;
    if(a[2*m]!=a[3*m-1])flg=false;
    if((a[0]^a[m])!=a[2*m])flg=false;
    if(flg)puts("Yes");
    else puts("No");
}
