#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m;
  int64_t sum=0;
  bool t=true;
  cin >> n >> m;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  sort(a,a+n,greater<int>());
  for(int i=0;i<m;i++){
    if(a[i]<(double)sum/(4*m)){
    t=false;
    cout << "No" << endl;
      break;
    }
  }
  if(t)cout << "Yes" << endl; 
}
