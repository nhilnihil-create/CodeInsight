#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int x;cin >>x;
    int q=x/100;
    int r=x%100;
    int cnt=(r+4)/5;
    if(cnt<=q)puts("1");
    else puts("0");
}
