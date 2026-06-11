
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}

int main(void){
    int n;
    ll r,g,b;
    string s;
    cin>>n>>s;
    r=g=b=0;
    rep(i,0,n){
        if(s[i]=='R')r++;
        else if(s[i]=='G')g++;
        else b++;
    }
    ll rgb=r*g*b;
    //cout<<rgb<<endl;
    rep(j,1,n){
        rep(i,0,j){
            int k=2*j-i;
            if(k<n){
                if(s[i]==s[j] || s[i]==s[k] || s[j]==s[k])continue;
                rgb--;
            }
        }
    }
    cout<<rgb<<endl;
    return 0;

}