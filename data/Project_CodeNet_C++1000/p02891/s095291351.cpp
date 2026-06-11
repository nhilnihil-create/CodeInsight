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
   string S;
   cin>>S;
   long long K;
   cin>>K;
   int N=S.size();
   if(S==string(N,S[0])){
      cout<<N*K/2<<endl;
   }else{
      int ans1=0;
      for(int i=0;i<N-1;i++){
         if(S[i]==S[i+1]){
            ans1++;
            i++;
         }
      }
      int ans2=0;
      for(int i=0;i<2*N-1;i++){
         if(S[i%N]==S[(i+1)%N]){
            ans2++;
            i++;
         }
      }
      cout<<ans1+(ans2-ans1)*(K-1)<<endl;
   }
   return 0;
}
