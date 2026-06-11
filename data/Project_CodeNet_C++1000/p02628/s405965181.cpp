#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//171B

int main(){
    int n,k;
    cin>>n>>k;

    int p[n];
    rep(i,n) cin>>p[i];

    sort(p,p+n);
    int m=0;
    rep(i,k){
        m+=p[i];
    }
    cout<<m<<endl;
}