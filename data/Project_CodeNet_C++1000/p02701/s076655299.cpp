#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  map<string, bool> kind;
  string tmp;
  for(int i = 0; i < N; i++){
    cin >> tmp;
    kind[tmp] = true;
  }
  
  cout << kind.size() << endl;
  

}
      

