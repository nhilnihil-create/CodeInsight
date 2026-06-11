#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int n,k,q;
  cin>>n>>k>>q;
  vector<int> a(q);
  rep(i,q) cin>>a[i];
  vector<int> st(n,k-q);
  rep(i,q) st[a[i]-1]++;
  rep(i,n){
    if(st[i]>0){
      cout<<"Yes"<<endl;
    }
    if(st[i]<=0){
      cout<<"No"<<endl;
    }
  }
}