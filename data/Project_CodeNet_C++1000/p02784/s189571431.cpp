#include <bits/stdc++.h>
using namespace std;

int main()
{
   long long int H,N;
   long long int sum=0;
   cin>>H>>N;
   long long int A[N];
   for(int i=0;i<N;i++){
       cin>>A[i];
   }
   for(int j=0;j<N;j++){
       sum+=A[j];
   }
   if(sum>=H){
       cout<<"Yes";
   }
   else{
       cout<<"No";
   }

    return 0;
}