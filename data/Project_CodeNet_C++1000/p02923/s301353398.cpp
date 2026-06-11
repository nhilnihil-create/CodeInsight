#include<bits/stdc++.h>

using namespace std;

int main(){

     long long n,b=0,c=0;

     cin>>n;

     long long a[n];

     for(int i=0;i<n;i++) cin>>a[i];

     for(int i=0;i<n-1;i++){

      if(a[i]>a[i+1] || a[i]==a[i+1]){ 

       b++;

     c=max(b,c);

    // cout<<c<<" ";

}

   else b=0;

}

      cout<<c<<endl;

     

     

}