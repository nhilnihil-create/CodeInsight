#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
#define mod 1000000007
#define pll pair<long long,long long>
using namespace std;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans;
        
}
bool prime[100005];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int R,S,P;
    cin>>R>>S>>P;
    string s;
    cin>>s;
    int ans=0;
    int i=0;
    while(i<n){
        if(i<k){
            if(s[i]=='r'){
                ans+=P;
                s[i]='p';
                i++;
            }
            else if(s[i]=='p'){
                ans+=S;
                s[i]='s';
                i++;
            }
            else if(s[i]=='s'){
                ans+=R;
                s[i]='r';
                i++;
            }
        }
        else{
            if(s[i]=='r'&&s[i-k]!='p'){
                ans+=P;
                s[i]='p';
                i++;
            }
            else if(s[i]=='p'&&s[i-k]!='s'){
                ans+=S;
                s[i]='s';
                i++;
            }
            else if(s[i]=='s'&&s[i-k]!='r'){
                ans+=R;
                s[i]='r';
                i++;
            }
            else{
                s[i]='#';
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}