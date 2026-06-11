#include<bits/stdc++.h>
using namespace std;


int main(void){
   int N;
   cin>>N;
   vector<int> v(N);
   map<int,int>b;
   for(int i=1;i<N;i++){
   cin>>v[i];
   }
   for(int i=1;i<N;i++){
     b[v[i]]++;
   }
   for(int i=1;i<=N;i++){
     cout<<b[i]<<endl;
   }
    return 0;
}


