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
    int n,cnt=0;
    string s;
    cin>>n>>s;
    rep(i,n-2){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') cnt++;
    }
    cout<<cnt<<endl;
}