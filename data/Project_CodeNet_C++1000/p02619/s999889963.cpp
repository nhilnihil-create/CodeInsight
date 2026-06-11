#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
typedef long long ll;
//
int last(int d,int i,vector<int> answer){
   
      int t=0;
    for(int k=1;k<=d;k++){
       
       if(i==answer[d-k]) break;
       t++;
    }
   return t;
}
int down(int d,int i,vector<vector<int>> point,vector<int> dism){
   rep(i,26){

   }
}
int main(){
   int D;cin>>D;
   vector<int> dism;
   rep(i,26){
      int a;cin>>a;
      dism.push_back(a);
   }
   vector<vector<int>> point(D,vector<int>(26,0));
   rep(i,D){
      rep(j,26){
         int s;cin>>s;
         point[i][j]=s;
      }
   }
   vector<int> answer;
   rep(i,D){
      int a;cin>>a;
      answer.push_back(a-1);
   }
   int ans=0;
   rep(i,D){
      ans=ans+point[i][answer[i]];
      rep(j,26){
       ans=ans-(dism[j]*(last(i+1,j,answer)));
      }
      cout<<ans<<endl;
      
   }
 //  rep(i,26){  cout<<last(1,i,answer);}
}