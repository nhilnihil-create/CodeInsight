#include <iostream>
#include <vector>
using namespace std;

/*
int linearSearch(vector<int> S, int key){
  for(int i = 0; i < S.size(); i++){
    if(S[i] == key) return i;
  }
  return -1;
}
*/

int linearSearch(vector<int> S, int key){
  int i = 0;
  while(S[i] != key) i++;
  if(i == S.size() - 1) return -1;
  else return i;
}

int main(void){
  vector<int> S;
  int n, q, cnt = 0;

  cin >> n;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    S.push_back(num);
  }

  cin >> q;
  for(int i = 0; i < q; i++){
    int key;
    cin >> key;
    S.push_back(key);
    if(linearSearch(S, key) >= 0) cnt++;
    S.erase(S.begin() + S.size() - 1);
  }
  cout << cnt << endl;
  return 0;
}