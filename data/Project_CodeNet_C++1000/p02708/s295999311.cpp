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
   long long K,N;
   cin>>N>>K;
   long long ans=0;
   for(long long i=K;i<=N+1;i++){
      long long mini=i*(i-1)/2;
      long long maxi=(N+N-i+1)*i/2;
      ans+=(maxi-mini+1);
   }
   cout<<ans%mod<<endl;
   return 0;
}