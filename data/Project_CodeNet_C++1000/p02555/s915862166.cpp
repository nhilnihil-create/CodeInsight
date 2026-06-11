#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
    long long minu(long long a, long long b){
        return mod(mod(a)-mod(b));
    }
    ll modPow(ll a, ll b){
        if(b==0)
            return 1LL;
        if(b==1)
            return a%M;
        ll res=1;
        while(b){
            if(b%2==1)
                res=mul(res,a);
            a=mul(a,a);
            b=b/2;
        }
        return res;
    }
    
    vector<int>dirX={-1,0,1};
    vector<int>dirY={-1,0,1};
 
 
    ll dp[2005];
    ll ok(int s){
        // cout<<"in "<<s<<"\n";
        if(s==0)
            return 1LL;
        else if(s==1 || s==2)
            return 0LL;
        else if(s>=3 && s<=5)
            return 1LL;
        else if(dp[s]!=-1)
            return dp[s];
        else{
            ll total=0;
            for(int i=3;i<=s;i++){
                if(s-i>=0)
                    total=add(total,ok(s-i));
            }
            return dp[s]=total;
        }
    }
    void solve(){
        int s;
        cin>>s;
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        cout<<ok(s);
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        // cin>>t;
        for(int i=1;i<=t;i++){
        //    cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }