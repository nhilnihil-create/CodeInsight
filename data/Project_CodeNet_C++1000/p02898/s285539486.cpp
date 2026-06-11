#include <iostream>
#include <vector>

using namespace std;

int main () {
   int N,K,i,x=0;
   cin>>N>>K;
   vector<int> h(N);
   for(i=0;i<N;i++){
       cin>>h[i];
	   if(K<=h[i])
		   x++;
   }
   cout<<x;
   return 0;}
