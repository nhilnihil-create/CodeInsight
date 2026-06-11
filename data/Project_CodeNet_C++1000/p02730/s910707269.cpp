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
    string s;
    cin>>s;
    int n=s.size();
    rep(i,(n-1)/2){
        if(s[i]!=s[n-1-i]){
            cout<<"No";
            return 0;
        }
    }
    rep(i,((n-1)/2)/2){
        if(s[i]!=s[(n-1)/2-1-i]){
            cout<<"No";
            return 0;
        }
    }
    rep(i,((n-1)/2)/2){
        if(s[(n-1)/2+1+i]!=s[n-1-i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}