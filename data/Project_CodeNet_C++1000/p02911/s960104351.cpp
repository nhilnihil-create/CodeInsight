#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef vector<int> vec;
int main(){
  int a,n,k,q;cin>>n>>k>>q;
  int o[n];
  rep(i,n)o[i]=0;
  
  rep(i,q){
    cin>>a;
    o[a-1]++;
  }
  
  rep(i,n){
    cout<<(k-q+o[i]>0?"Yes":"No")<<endl;
  }

}