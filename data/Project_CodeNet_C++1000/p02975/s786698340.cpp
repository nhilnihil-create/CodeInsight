#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> a(N);
  cin >> a.at(0);
  int64_t ans=a.at(0);
  for(int i=1;i<N;i++){
    cin >> a.at(i);
    ans^=a.at(i);
  }
  if(ans==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
