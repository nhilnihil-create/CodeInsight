#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[200005];
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int ans=unique(a,a+n)-a;
  if(ans==n)
  {
  	cout<<"YES"<<endl;
   }
   else
   cout<<"NO"<<endl; 
  } 