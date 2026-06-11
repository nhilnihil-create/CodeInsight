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
    int A,B,M;cin >>A>>B>>M;
    vector<int>a(A);
    int mina=INF;
    int minb=INF;
    for (int i = 0; i < A; ++i) {
        cin >>a[i];
        mina=min(mina,a[i]);
    }
    vector<int>b(B);
    for (int i = 0; i < B; ++i) {
        cin >>b[i];
        minb=min(minb,b[i]);
    }
    vector<int>x(M);
    vector<int>y(M);
    vector<int>c(M);
    int ans=mina+minb;
    for (int i = 0; i < M; ++i) {
        cin >>x[i]>>y[i]>>c[i];
        x[i]--;y[i]--;
        ans=min(ans,a[x[i]]+b[y[i]]-c[i]);
    }
    cout <<ans <<endl;
}
