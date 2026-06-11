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
    ll n,k;
    cin>>n>>k;
    vector<int> a(n+1),b(n+1);
    repi(i,1,n+1) cin>>a[i];
    int cnt=0,i=1;
    while(cnt<k){
        if(b[i]==0) b[i]=cnt;
        else{
            b[i]=cnt-b[i];
            k=(k-cnt)%b[i];
            break;
        }
        if(cnt==k-1){
            cout<<a[i];
            return 0;
        }
        i=a[i];
        cnt++;
    }
    rep(j,k) i=a[i];
    cout<<i;
}