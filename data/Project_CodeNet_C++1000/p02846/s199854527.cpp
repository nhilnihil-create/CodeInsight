#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll T1,T2,A1,A2,B1,B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  ll a=T1*(A1-B1),b=T2*(A2-B2);
  if(a<0){a*=-1;b*=-1;}
  if(a+b>0){cout<<"0"<<endl;return 0;}
  if(a+b==0){cout<<"infinity"<<endl;return 0;}
  ll dp=a,ans=0;
  if(a%(a+b)==0){cout<<-2*(a/(a+b))<<endl;return 0;}
  if(a%(a+b)!=0){cout<<-2*(a/(a+b))+1<<endl;return 0;}
}