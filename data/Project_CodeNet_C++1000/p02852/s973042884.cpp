#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
  int N,M;
  cin >> N >> M;
  string str;
  cin >> str;
  int loc = N;
  vector<int> v;
  while(loc > 0){
    int n=M;
    for(n=M;n>=1;n--){
      if(loc - n >= 0){
        if(str[loc - n] == '0')
          break;
      }
    }
    if(n == 0){
       cout << -1 << endl;
       return 0;
    }
    v.push_back(n);
    loc = loc - n;
    //cout << loc << " "<< str[loc] << endl;
  }
  for(int i=v.size()-1;i>=1;i--){
    cout << v[i] << " ";
  }
  cout << v[0] << endl;
  return 0;
}