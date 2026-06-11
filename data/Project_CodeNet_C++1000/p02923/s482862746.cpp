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
    int n,cnt=0,maxi=0; cin>>n;
    vector<ll> h(n+1);
    h[0]=0;
    repi(i,1,n+1){
        cin>>h[i];
        if(h[i-1]>=h[i]) cnt++;
        else{
            maxi=max(maxi,cnt);
            cnt=0;
        }
    }
    maxi=max(maxi,cnt);
    cout<<maxi;
}