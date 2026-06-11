#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  for(int i=0;i<m;i++){
    cin>>a[i];
    n-=a[i];
  }
  if(n<0){
    cout<<"-1"<<endl;
  }
  else {
    cout<<n<<endl;
  }
}