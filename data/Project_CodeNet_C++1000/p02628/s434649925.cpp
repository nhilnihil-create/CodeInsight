#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test=1;
    //cin>>test;
    while(test--){
      int n,k;
      cin>>n>>k;
      int a[n];
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      sort(a,a+n);
      int s=0;
      for(int i=0;i<k;i++) s+=a[i];
      cout<<s;
    }
    

    return 0;
}
