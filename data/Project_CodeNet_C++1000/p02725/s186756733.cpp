#include<bits/stdc++.h>
using namespace std;
 
int main(){
        int k,n;
        cin>>k>>n;
        int a[n], x;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
      int ans = k;
      for(int i=1;i<n-1;i++) ans = min(ans,k-(a[i+1]-a[i]));
      ans = min(ans,k-(a[0]+k-a[n-1]));
      cout << ans;
}