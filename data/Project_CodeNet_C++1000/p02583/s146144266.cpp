#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  //cout << M << endl;*/

  //int N = 3;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }

  std::sort(vec.begin(), vec.end());
  //sort(vec.begin(), vec.end());
  //vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

  /*for (int i = 0; i < vec.size()-1; i ++){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(vec.size() - 1) << endl;*/

  int ans=0;

  /*for(int i = 0; i < vec.size()-2; i++){
    for(int j = i+1; j < vec.size()-1; j++){
      for(int k = j+1; k < vec.size(); k++){
        if(vec.at(i) != vec.at(j) && vec.at(j) != vec.at(k) && vec.at(i) + vec.at(j) > vec.at(k)){
            //cout << vec.at(i) << " " << vec.at(j) << " " << vec.at(k) << endl;
            ans++;
        }
      }
    }
  }*/

  for(int i = 0; i < vec.size(); i++){
    for(int j = 0; j < i; j++){
      for(int k = 0; k < j; k++){
        if(vec.at(i) != vec.at(j) && vec.at(j) != vec.at(k) && vec.at(k) + vec.at(j) > vec.at(i)){
            //cout << vec.at(i) << " " << vec.at(j) << " " << vec.at(k) << endl;
            ans++;
        }
      }
    }
  }

  cout << ans << endl;

  //vector<int> vec(N);
  /*for (int i = 0; i < vec.size(); i ++){
    cout << vec.at(i) << endl;
  }*/


  /*for (int i = 0; i < vec.size()-1; i ++){
    cout << vec.at(i) << " ";
  }
  cout << vec.at(vec.size() - 1) << endl;*/
}
