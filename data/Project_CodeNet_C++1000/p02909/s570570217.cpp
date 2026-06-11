#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S,T;
   cin>>S;
   
   if(S=="Sunny"){
       T="Cloudy";
   }
   else if(S=="Cloudy"){
       T="Rainy";
   }
   else{
       T="Sunny";
   }
    cout<<T<<endl;

}
