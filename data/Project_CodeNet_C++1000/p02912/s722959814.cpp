#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;

bool sort_sec(const pair<int,int> &a,const pair<int,int> &b){
   if(a.second<b.second){
      return true;
   }
   return false;
}

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}

int main(void){
   int N,M;
   cin>>N>>M;
   vector<int> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   priority_queue<int> que;
   for(int i=0;i<N;i++){
      que.push(A[i]);
   }

   while(M!=0){
      M=M-1;
      int v=que.top();
      que.pop();
      int mv=v/2;
      que.push(mv);
   }
   long long ans=0;
   for(int i=0;i<N;i++){
      ans+=que.top();
      que.pop();
   }
   cout<<ans<<endl;
   return 0;
}
