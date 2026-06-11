#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  string s;
  cin >> s;
  int a0=0,a1=1;
  int na0,na1;
  int r=0;
  for(int i=0;i<s.size();i++){
    r=s[i]-'0';
    if(r==9){
      na0=a1+1;
      na1=a1;
    }else{
      na0=min(a0+r,a1+10-r);
      na1=min(a0+r+1,a1+9-r);
    }
    a0=na0; a1=na1;
    //cout << a0 << " " << a1 << endl;
  }

  cout << na0 << endl;
  
  return 0;
}
