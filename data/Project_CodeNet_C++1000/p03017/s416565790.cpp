#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
  int kazu = 0;
  int as,bs,ag,bg;
  cin >> kazu >> as >> bs >> ag >> bg;
  string masu;
  cin >> masu;
  int kotae = 0;
  int iwa = 0;
  for(int i = as - 1;i <= max(ag,bg) - 1;i++){
    if(masu[i] == '#'){
      iwa++;
    }
    else{
      iwa = 0;
    }
    if(iwa >= 2){
      kotae = 1;
      i = max(ag,bg);
    }
  }
  if(kotae == 0 && ag > bg){
    int ikeru = 0;
    int nukeruka = 0;
    for(int i = bs - 2;i <= bg;i++){
      if(masu[i] == '.'){
        ikeru++;
      }
      else{
        ikeru = 0;
      }
      if(ikeru >= 3){
        nukeruka = 1;
        i = ag;
      }
    }
    if(nukeruka == 0){
      kotae = 1;
    }
  }
  if(kotae == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}
