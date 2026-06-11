#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <math.h>
#include <list>
using namespace std;

int main(void){
  string s;

  cin >> s;
  int Q;
  cin >> Q;
  int dir = 1;
  list<char>neko;
  for(int i =0; i < s.size(); i++){
      neko.push_back(s[i]);
  }
  for(int i =0; i < Q; i++){
    int T1;
    cin >> T1;
    switch(T1)
    {
    case 1:
      dir *= -1;
      break;
    case 2:
      int T2;
      cin >> T2;
      char c;
      cin >> c;
      if(T2 == 2){
        if(dir == -1){
          neko.push_front(c);
        }else{
          neko.push_back(c);
        }
      }else{
        if(dir == -1){
          neko.push_back(c);
        }else{
          neko.push_front(c);
        }
      }
      break;
    }
  }

  if(dir == -1){
    reverse(neko.begin(), neko.end());
  }
  for(auto it = neko.begin(); it != neko.end(); ++it){
    cout << *it;
  }
  cout << endl;
  return 0;
}