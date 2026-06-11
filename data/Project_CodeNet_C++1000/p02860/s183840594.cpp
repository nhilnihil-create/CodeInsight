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
    string s;
    cin>>n>>s;
    int len=s.size();
    if(len%2==1) cout<<"No";
    else{
        rep(i,len/2){
            if(s[i]!=s[i+len/2]){
                cout<<"No";
                return 0;
            }
        }
        cout<<"Yes";
    }
}