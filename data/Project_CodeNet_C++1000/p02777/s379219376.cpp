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
    string s,t,u;
    int a,b;
    cin>>s>>t>>a>>b>>u;
    if(s==u) cout<<a-1<<" "<<b;
    else cout<<a<<" "<<b-1;
}