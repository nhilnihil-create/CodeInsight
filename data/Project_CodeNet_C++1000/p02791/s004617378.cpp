#include<bits/stdc++.h>
using namespace std;




int main(void){
   int N; 
   cin>>N;
   vector<int> v(N);
   for(int i=0;i<N;i++){
      cin>>v[i];
   }
   int a=0;
   int minn=1e9;
   for(int i=0;i<N;i++){
minn=min(minn,v[i]);
if(minn==v[i]){
   a++;
}
   }
   cout<<a<<endl;
 return 0;
}


