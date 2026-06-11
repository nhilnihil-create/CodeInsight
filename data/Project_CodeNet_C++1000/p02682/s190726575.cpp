#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
   ll a,b,c,k,sum=0;
   cin>>a>>b>>c>>k;
   if(k<=a){
        cout<<k<<endl;
   }
   else{
        sum+=a;
        k-=a;
        if(k<=b){
            cout<<sum<<endl;
        }
        else{
            k-=b;
            cout<<sum-min(k,c)<<endl;
        }

   }

}
