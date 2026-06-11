#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
main(){
  int n,sum=0;
  cin>>n;
  int a[n];
  r(i,n)cin>>a[i];
  sort(a,a+n);
  int p;
  cin>>p;
  while(p--){
    int x;
    cin>>x;
    int l=0,r=n;
    while(l<r){
      int mid=(l+r)/2;
      if(a[mid]==x){sum++;break;}
      if(a[mid]>x)r=mid;
      else l=mid+1;
    }
  }
  cout<<sum<<endl;
}