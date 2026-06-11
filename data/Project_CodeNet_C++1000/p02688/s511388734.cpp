#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,k,num;
    cin>>n>>k;
    vector<int> d(k),ans(n);
    rep(i,n) ans[i]=0;
    rep(i,k){
        int d;
        cin>>d;
        rep(j,d){
            cin>>num;
            ans[num-1]++;
        }
    }
    int cnt=0;
    rep(i,n) if(ans[i]==0) cnt++;
    cout<<cnt;
}