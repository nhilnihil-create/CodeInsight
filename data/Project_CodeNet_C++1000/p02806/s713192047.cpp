#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define F first
#define S second
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()
//library begin
int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int log(int a){
    int b=a;
    int cnt=0;
    while(b%2==0){
        b/=2;
        cnt++;
    }
    return cnt;
}
//library end
int n;
string s[60];
int t[60];
string x;
int ans=0;
bool awake=true;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>s[i]>>t[i];
    }
    cin>>x;
    rep(i,n){
        if(!awake)ans+=t[i];
        if(s[i]==x)awake=false;
    }
    cout<<ans<<endl;
    return 0;
}

