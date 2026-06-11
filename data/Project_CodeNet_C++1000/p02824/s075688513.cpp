#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,v,p;
  ll m; //n=problem,m=judge,v=voting,p=select
  cin>>n>>m>>v>>p;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  ll z;
  sort(vec,vec+n);
  reverse(vec,vec+n);
  if(vec[n-1]+m>=vec[p-1]){
    if(v<=p){
      cout<<n<<endl;
      return 0;
    }
    if(v>p){
      z=0;
      for(int i=p-1;i<n-1;i++){
        z+=vec[n-1]+m-vec[i];
      }
      if(z>=(v-p)*m){
        cout<<n<<endl;
        return 0;
      }
    }
  }
  int ok=p-1,ng=n-1,search;
  for(int query=0;query<20;query++){
    search=(ok+ng)/2;
    if(vec[search]+m<vec[p-1]){
      ng=search;
      continue;
    }
    if(v<=p){
      ok=search;
      continue;
    }
    z=0;
    for(int i=p-1;i<n;i++){
      if(i!=search){
        z+=min(m,vec[search]+m-vec[i]);
      }
    }
    if(z>=(v-p)*m){
      ok=search;
    }
    else{
      ng=search;
    }
  }
  cout<<ok+1<<endl;
}