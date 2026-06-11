#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;

  cin >> N;
  vector<int> vec(N);
  vector<int> array(N);

  for(int i=0;i<N;++i){
    cin >> vec.at(i);
    array.at(i) = vec.at(i);
  }

  sort(vec.begin(),vec.end());
  for(int i=0;i<N;++i){
    if(array.at(i) == vec.at(N-1)){
      cout << vec.at(N-2) << endl;
    }else{
      cout << vec.at(N-1) << endl;
    }
  }
  return 0;
}
