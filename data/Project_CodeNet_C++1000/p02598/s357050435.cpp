#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  int a[n];int mi =1,ma = -1;
  for (int i=0;i<n;++i){cin>>a[i];ma=max(ma,a[i]);}
  sort(a,a+n);int ans =ma;
  while (mi<=ma){
      int mid = (mi+ma)/2;
      int te = k;
      for (int i=n-1;i>=0;--i){
          if (a[i]<=mid)break;
          te-=((a[i]-1)/mid);
      }
      if (te>=0){ans=mid;ma=mid-1;}
      else mi=mid+1;
  }
  cout<<ans;
  
}