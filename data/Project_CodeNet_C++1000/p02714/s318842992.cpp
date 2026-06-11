#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI 3.1415926535897932384626433832795028841971693993
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n,ans=0;
    string s;
    cin>>n>>s;
    ll a=0,b=0,c=0;
    rep(i,n){
        if(s[i]=='R') a++;
        else if(s[i]=='G') b++;
        else c++;
    }
    ll sum=a*b*c;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            int k=2*j-i;
            if(n<=k) continue;
            if(i>=j||j>=k||i>=k) continue;
            if(s[i]!=s[j]&&s[j]!=s[k]&&s[k]!=s[i]) sum--;
        }
    }
    cout<<sum<<endl;
}