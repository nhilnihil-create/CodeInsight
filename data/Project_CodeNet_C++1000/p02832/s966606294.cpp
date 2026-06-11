#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i< n; i++){
    cin >> a[i];
  }

  int brick = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == brick+1) {
      brick++;
    }
  }
  if(brick== 0){
    cout << -1 << endl;
  } else {
    cout << a.size() - brick << endl;
  }
  return 0;
} 
