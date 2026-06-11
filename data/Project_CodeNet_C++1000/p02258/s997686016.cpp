#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  long  n,r,minv=10000000000,maxv=-10000000000;
  // int n,r;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> r;
    maxv = max(maxv,r-minv);
    minv = min(minv,r);
    
    //  cout << "maxv " <<  maxv << endl;
    //  cout << "minv " <<  minv << endl;
    
  }

  cout << maxv << endl;
  return 0;
}