#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main(){
  long h, n;
  cin >> h >> n;

  vector<int> a;
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  long sum = accumulate(a.begin(), a.end(), 0);
  if(h <= sum){
    cout << "Yes" << endl;
  } else{
    cout << "No" <<endl;
  }
  return 0;
}

