#include<bits/stdc++.h>
using namespace std;
int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);
   long long int i,n,x,k=0,input;
    cin>>n;
    x=n+1;
    for(i=0; i<n; i++){
        cin>>input;
        if(input<x){
            k++;
            x=input;
        }
    }
    cout<<k<<"\n";
    return 0;
}
