#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main( )
{
     ll N;
     cin>>N;
     if(N%2 == 1){
         cout<<"0"<<endl;
     }
     else{
         ll cnt=0;
         N /= 2;
         for(ll i=5;(N/i)>=1;i *= 5){
             cnt += (N/i);
         }
         cout<<cnt<<endl;
     }
}