#include<bits/stdc++.h>

using namespace std;
#define ll long long 



int main(void){
   ll N,K;
   cin>>N>>K;
   ll a=N%K;
   ll b= min(a,K-a);
   cout<<b<<endl;
   
   
   return 0;
   
}


