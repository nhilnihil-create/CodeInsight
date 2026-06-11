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

int main(void)
{
    string s;
    cin>>s;
    rep(i,0,s.size()){
        if(s[i]=='?'){
            if(s[i-1]=='P') s[i]='D';
            else{
                if(s[i+1]=='D')s[i]='P';
                else s[i]='D';
            }
        }
    }
    cout<<s<<endl;
}