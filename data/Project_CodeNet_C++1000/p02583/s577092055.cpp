#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> v(n);
  int i,j,k;
  for(i=0;i<n;i++) cin >> v[i];
  if(n<=2){
    cout << 0 << "\n";
    return 0;
  }
  int cnt = 0;
  sort(v.begin(),v.end());
  for(i=0;i<n-2;i++){
    for(j=i+1;j<n-1;j++){
      for(k=j+1;k<n;k++){
        if((v[i]!=v[j])&&(v[j]!=v[k])&&(v[i]+v[j]>v[k])){
          cnt++;
        }
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}                                                                                      