#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int test=1;
    //cin>>test;
    while(test--){
      int n;
      cin>>n;
      int a[n];
      int x=0;
      for(int i=0;i<n;i++) {
        cin>>a[i];
        x^=a[i];
      }
      for(int i=0;i<n;i++){
        cout<<(x^a[i])<<" ";
      }

      
    }
    

    return 0;
}
