#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <map>
#include <string.h>
#include <vector>
#include <cmath>
#include <deque>
#include <iomanip>

using namespace std;
#define range(a) a.begin(), a.end()
#define rep(i, c) for(int i = 0; i < (int)c; i++)
typedef long long ll;

const string YES = "Yes";
const string NO = "No";


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  string ans;
  cin >> s;
  rep(i, 5){
    ans += "hi";
    if(ans == s){
      cout << YES << endl;
      return 0;
    }
  }
  cout << NO << endl;




  return 0;

}
