#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(int)(n);i++)
using namespace std;
using p=pair<int,int>;


int main() {

  int n;
  cin>>n;

  long min1=2000000000;
  long min2=2000000000;
  long max1=-2000000000;
  long max2=-2000000000;


  rep(i,n){
    long x,y;
    cin>>x>>y;
    if(x+y>max1)max1=x+y;
    if(x-y>max2)max2=x-y;
    if(x+y<min1)min1=x+y;
    if(x-y<min2)min2=x-y;
  }

  long ans=max(max1-min1,max2-min2);

  
  cout<<ans<<endl;
  return 0;

}
