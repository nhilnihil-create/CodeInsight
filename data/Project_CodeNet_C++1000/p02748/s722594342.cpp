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
    int A,B,M;
    cin>>A>>B>>M;
    vector<int> a(A),b(B);
    int x,y,c,mini,amini=100010,bmini=100010;
    rep(i,A){
        cin>>a[i];
        amini=min(amini,a[i]);
    }
    rep(i,B){
        cin>>b[i];
        bmini=min(bmini,b[i]);
    }
    mini=amini+bmini;
    rep(i,M){
        cin>>x>>y>>c;
        mini=min(mini,a[x-1]+b[y-1]-c);
    }
    cout<<mini;
}