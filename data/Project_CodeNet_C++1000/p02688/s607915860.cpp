#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  
  vector<int> sunuke;
  for (int i=0 ; i<N ; i++)
    sunuke.push_back(i+1);
  
  vector<int> d(K);
  for (int i=0 ; i<K ; i++){
    cin >> d.at(i);
    vector<int> A(d.at(i));
    for (int j=0 ; j<d.at(i) ; j++){
      cin >> A.at(j);
      sunuke.erase(remove(sunuke.begin(), sunuke.end(), A.at(j)), sunuke.end());
    }
  }
  
  cout << sunuke.size() << endl;
}