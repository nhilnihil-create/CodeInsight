#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,b)  for(int i=0;i<(int)(b);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    cs
    string s;int n,p;ll t=0;
    cin>>n>>p>>s;
    if(p==2) {
        rep(i,n) {
            if((s[i]-'0')%2==0) t+=i+1;
        }
    }
    else if(p==5) {
        rep(i,n) {
            if((s[i]-'0')%5==0) t+=i+1;
        }
    }
    else {
        map<int,int> pam;int tt=0,base=1;
        pam[0]++;
        Repp(i,n-1,0) {
            tt+=(s[i]-'0')*base;
            tt%=p;
            t+=pam[tt];
            pam[tt]++;
            base=(base*10)%p;
        }
    }
    cout<<t;
}