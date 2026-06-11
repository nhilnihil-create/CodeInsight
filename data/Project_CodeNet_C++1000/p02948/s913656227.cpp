#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<pair<long,long>>a;
 
  rep(i,n){
    int A,B;
    cin >> A>>B;
    a.push_back(pair<int,int>(A,B));
  }
  sort(a.begin(), a.end());
  
  int ans=0;
  int k=0;
  
  priority_queue<int>p;
  rep2(i,1,m+1){
    rep2(j,k,n){
      if(a[j].first==i){
        p.push(a[j].second);
      }
      else{
        k=j;
        break;
      }
    }
    if(!p.empty()){
      ans+=p.top();
      p.pop();
    }
  }
    
  
  cout<<ans<<endl; 
}