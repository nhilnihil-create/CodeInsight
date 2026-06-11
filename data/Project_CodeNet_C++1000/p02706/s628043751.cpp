#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,a,SUM=0;
  cin >> n >> m ;
  for(int i=0;i<m;i++){
    cin >> a;
    SUM+=a;
  }
  if(n-SUM>=0){
    cout << n-SUM <<endl;
  } else {
    cout << -1<<endl;
  }
}
