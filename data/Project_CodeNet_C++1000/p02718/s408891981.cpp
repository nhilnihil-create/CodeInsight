#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  vector<int> a(n);
  int all=0;
  for(int &i:a){
    cin>>i;
    all+=i;
  }
  sort(a.rbegin(),a.rend());
  for(int i=0;i<m;i++){
    if(4*m*a[i]<all){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}