#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  vector<int> a;
  while(cin >> n, n){
    a.clear();
    a.resize(n);
    int res = 99999999;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
      if(abs(a[i]-a[i+1])<res){
        res = abs(a[i]-a[i+1]);
      }
    }
    cout << res << endl;
  }
}