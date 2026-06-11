#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  bool boo=true;
  cin >> N;
  vector<long long>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  for(int i=N-2; i>=0; i--){
    if(vec[i+1] < vec[i]){
      if(vec[i]-1 != vec[i+1]){
        boo=false;
      }
      else{
        vec[i]--;
      }
    }
  }
  if(boo){
    cout << "Yes" << endl;
    return 0;
  }
    cout<<"No"<<endl;
}
