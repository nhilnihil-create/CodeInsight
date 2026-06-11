#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll m[N],s[N];
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
   cin>>n;
   for(int i=0;i<n+1;i++){
    cin>>m[i];
   }
   for(int i=0;i<n;i++){
    cin>>s[i];
   }
   ll ans=0;
   for(int i=0;i<n;i++){
    if(m[i]>s[i]){
       ans+=s[i];
       s[i]=0;


    }else {
    ans+=m[i];
    s[i]-=m[i];
    m[i]=0;
    ans+=min(s[i],m[i+1]);
    m[i+1]-=s[i];
    m[i+1]=max(m[i+1],1LL*0);



    }
   }

   cout<<ans;


    return 0;
}
