#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n, box=0, zero=0;
  cin >> n;
  int a[n], b[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i]==0) zero++;
  }
  vector<int> c;
  for(int i=n-1; i>n/2-1; i--){
    if(a[i]==1) {b[i]=1; box++; c.push_back(i+1);}
    else b[i]=0;
  }
  for(int i=n/2-1; i>=0; i--){
    int m=n/(i+1), count=0;
    for(int j=2; j<=m; j++){
      count+=b[(i+1)*j-1];
    }
    if(count%2==0){
      if(a[i]==1) {b[i]=1; box++; c.push_back(i+1);}
      else b[i]=0;
    }
    else{
      if(a[i]==1) b[i]=0;
      else {b[i]=1; box++; c.push_back(i+1);}
    }
  }
  sort(c.begin(), c.end());
  if(zero==n) cout << "0";
  else if(box==0) cout << "-1";
  else{
    cout << box << endl;
    cout << c[0];
    for(int i=1; i<c.size(); i++){
      cout << " " << c[i];
    }
  }
  return 0;
}