#include <bits/stdc++.h>
using namespace std;
#define int long long



struct listnode{
 int val;
 listnode*  next;};
 vector<int> func( vector<int> a,vector<int>l,int sum){
      vector<int>k,val;
       for(int i=0;i<l.size();i++)
           if(l[i]==0){
            k.push_back(i);
            val.push_back(a[i]);}
   if(sum<0)
   return a;
  else {
      sort(val.rbegin(),val.rend());
      for(int i=0;i<k.size();i++)
         a[k[i]]=val[i];}
         return a;

 }
 


int32_t main(){
 int m=1000000007;
 
     int n;
     cin>>n;
    int temp=n;
    int ans1=1,ans2=1;
    int ans=1;
     while(temp--!=0){
         ans1=(ans1*9)%m;
         ans2=(ans2*8)%m;
         ans=(ans*10)%m;
         
     }
     int a=(ans-(2*ans1)%m)%m;
    a=(a+ans2)%m;
     cout<<(a+m)%m<<endl;
     

return 0;
}