#include<bits/stdc++.h>
using namespace std;

#define lp(i,n) for(int i=0;i<n;i++)
#define lpin(a,i,n) for(int i=0;i<n;i++){cin>>a[i];}
int main(){
  while(1){
    int n;
    cin>>n;
    if(n==0) break;
    int a[1000];
    lpin(a,i,n);
    int ans=1000001,b;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
	if(a[i]>a[j]) b=a[i]-a[j];
	else b=a[j]-a[i];
	if(ans>b) ans=b;
      }
      if(b==0) break;
    }
    cout<<ans<<endl;
  }
  
  return 0;
}

