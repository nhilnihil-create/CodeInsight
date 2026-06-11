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
    ll n;
    cin>>n;
    string s;
    while(n>0){
        ll k=(n-1)%26;
        s+=char(k+'a');
        n=(n-1)/26;
    }
    reverse(all(s));
    cout<<s;
}