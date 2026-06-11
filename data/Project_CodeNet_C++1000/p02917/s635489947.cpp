#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
int gcd(int a,int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
int main(){
    int n;
     cin>>n;
     vector<int> b(n-1);
     for(int i=0;n-1>i;++i)
     cin>>b.at(i);

     vector<int> a(n);
     int ans=0;

     for(int i=0;n>i;++i){
         if(i==0)
         a.at(i)=b.at(i);
         else if(i==n-1)
         a.at(i)=b.at(i-1);
         else
         a.at(i)=min(b.at(i-1),b.at(i));
         ans+=a.at(i);
     }

     cout<<ans<<endl;
}