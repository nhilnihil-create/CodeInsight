#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,count=0,max=0;
    cin>>n;
    vector<string> s(n);
    rep(i,n){
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    rep(i,n-1){
        if(s[i]==s[i+1]){
            count++;
            if(max<count){
                max=count;
            }
        }else{
                count=0;
        }
    }
  count=0;
    rep(i,n-1){
        if(s[i]==s[i+1]){
            count++;
            
        }else{
                count=0;
        }
      if(max==count){
                cout<<s[i]<<endl;
            }
    }
  if(count==0&&max==0){
    cout<<s[n-1]<<endl;
  }
}