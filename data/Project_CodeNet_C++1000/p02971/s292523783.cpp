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
    vector<int> a(n),b(n);
    rep(i,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(all(b));
    reverse(all(b));
    rep(i,n){
        if(a[i]==b[0]) cout<<b[1];
        else cout<<b[0];
        cout<<endl; 
    }
}