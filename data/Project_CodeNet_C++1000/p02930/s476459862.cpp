#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)a[i]=i;
  vector<vector<int>>g(n,vector<int>(n,-1));
  
  rep(i,n-1){
    for(int j=i+1; j<n; ++j){
      int x;
      rep(k,30)if((i>>k)^(j>>k))x=k;
      cout<<x+1<<" ";
    }
    cout<<endl;
  }
}