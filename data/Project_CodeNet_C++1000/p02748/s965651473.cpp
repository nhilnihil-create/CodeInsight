#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int a,b,m;
    cin >> a >> b >> m;
    vector<int> A(a);
    vector<int> B(b);
    rep(i,a) cin >> A[i];
    rep(i,b) cin >> B[i];
    int mina=100100100,minb=100100100;
    rep(i,a) mina=min(mina,A[i]);
    rep(i,b) minb=min(minb,B[i]);
    int ans=mina+minb;
    for(int i=0;i<m;i++){
        int x,y,c;
        cin >> x >> y >> c;
        ans=min(ans,A[x-1]+B[y-1]-c);
    }
    cout << ans << endl;
}