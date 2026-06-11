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
    int n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d;
    cin>>s;
    bool cnt1=false,cnt2=false;
    repi(i,a-1,c) if(s[i]=='#'&&s[i]==s[i+1]) cnt1=true;
    repi(i,b-1,d) if(s[i]=='#'&&s[i]==s[i+1]) cnt1=true;
    if(c<d){
        if(!cnt1) cout<<"Yes";
        else cout<<"No";
    }
    else{
        repi(i,b-1,d) if(s[i-1]=='.'&&s[i]==s[i-1]&&s[i+1]==s[i]) cnt2=true;
        if((!cnt1)&&cnt2) cout<<"Yes";
        else cout<<"No";
    }
}