#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;


int main(){
    ll n,cnt=1,sum=0;
    string x;
    
    cin>>n;
  vector<string> s(n);
    rep(i,n){
        cin>>x;
        sort(x.begin(),x.end());
        s[i]=x;
    }
    sort(s.begin(),s.end());
    rep(i,n-1){
        if(s[i]==s[i+1]){
            sum+=cnt;
            cnt++;
        }else{
            cnt=1;
        }
    }
    cout<<sum;
}