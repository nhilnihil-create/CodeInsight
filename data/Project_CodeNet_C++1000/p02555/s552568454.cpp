#include<bits/stdc++.h>
using namespace std;


//pair
#define ff              first
#define ss              second

#define int             long long
#define endl            '\n'
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(t)            int t; cin>>t; while(t--)

const int M=1e9+7;
long long mod(long long x){
    return ((x%M + M)%M);
}
int add(int a, int b){
    return mod(mod(a)+mod(b));
}
int mul(int a, int b){
    return mod(mod(a)*mod(b));
}
int sub(int a, int b){
    return mod(mod(a)-mod(b));
}

int modPow(int a, int b){
    if(b==0)
        return 1LL;
    if(b==1)
        return a%M;
    int res=1;
    while(b){
        if(b%2==1)
            res=mul(res,a);
        a=mul(a,a);
        b=b/2;
    }
    return res;
}

int Pow(int a,int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int res=1;
    while(b){
        if(b%2==1)
            res=res*a;
        a=a*a;
        b=b/2;
    }
    return res;
}

int sumOfDigits(int n){
    int s = 0;
    while(n!=0){
        s=s+n%10;
        n=n/10;
    }
    return s;
}
int dp[2005];

int check(int s){

    if(s==1||s==2){
        return 0;
    }

    if(dp[s]!=-1){
        return dp[s];
    }
    int ans = 0;

    for(int i=3;i<=s;i++){
        if(s-i>=0){
            ans = add(ans,check(s-i));
        }

    }
    dp[s]=ans;
    return ans;
}

void solve(){
    int n;
    cin>>n;
    if(n<=2){
        cout<<0;
        return;
    }
    memset(dp,-1,sizeof(dp));
//    cout<<dp[n]<<endl;
    dp[0]=1;
    dp[3]=1;
    dp[4]=1;
    dp[5]=1;
    cout<<check(n);


}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}


