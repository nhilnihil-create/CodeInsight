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
    int n;
    cin>>n;
    vector<int> p(n),q(n),r(n);
    rep(i,n) cin>>p[i];
    rep(i,n) cin>>q[i];
    rep(i,n) r[i]=p[i];
    sort(all(r));
    int a,b;
    int cntp=0,cntq=0,nump=0,numq=0;
    do{
        rep(i,n){
            if(p[i]==r[i]) cntp++;
            if(q[i]==r[i]) cntq++;
        }
        if(cntp==n) a=nump;
        else nump++;
        if(cntq==n) b=numq;
        else numq++;
        cntp=0;
        cntq=0;
    }while(next_permutation(all(r)));
    cout<<abs(a-b);
}