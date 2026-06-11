#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;


int main(void){
   int N;
   cin>>N;
   vector<int> A(N),B(N);
   for(int i=0;i<N;i++){
      cin>>A[i]>>B[i];
   }
   vector<pair<int,int>> tasks;
   for(int i=0;i<N;i++){
      tasks.push_back(make_pair(B[i],A[i]));
   }
   sort(tasks.begin(),tasks.end());
   int now=0;
   bool flag=true;
   for(int i=0;i<N;i++){
      now+=tasks[i].second;
      if(now>tasks[i].first){
         flag=false;
         break;
      }
   }
   if(flag){
      cout<<"Yes"<<endl;
   }else{
      cout<<"No"<<endl;
   }
   return 0;
}