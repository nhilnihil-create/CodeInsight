#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
//
vector<int> light(vector<int> v){
   int N=v.size();
   vector<int> vv(N,0);
   rep(i,v.size()){
      int a,b;
      a=max(0,(i-v[i]));
      b=i+v[i]+1;
      vv[a]++;
      if(b<N)vv[b]--;
   }
   rep(i,vv.size()-1){
       vv[i+1]=min(vv[i+1]+vv[i],N);
   }
   return vv;
   
}

int main(){
   int N,K;
   cin>>N>>K;
   vector<int> v,check(N,N);
   if(K>2*N){
      vector<int> vv(N,N);
      for(auto e:v) cout<<e<<" ";
      cout<<endl;
      return 0;
   } 
   rep(i,N){
      int a;
      cin>>a;
      v.push_back(a);
   }
   rep(i,K){
      if(v==check) break;
      v=light(v);
      
   }
   for(auto e:v) cout<<e<<" ";
   cout<<endl;
}
    