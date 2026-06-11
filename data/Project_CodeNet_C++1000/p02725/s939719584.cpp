#include<bits/stdc++.h>

using namespace std;




int main(void){
   int K,N;
   int a=0;
   int maxx=0;
   cin>>K>>N;
   vector<int> v(N);
   for(int i=0;i<N;i++){
     cin>>v[i];
   }
   v.push_back(v[0]+K);
   for(int i=1;i<=N;i++){
     maxx=max(maxx,abs(v[i]-v[i-1]));
   }
   int b=K-maxx;
   cout<<b<<endl;

   return 0;
   
}


