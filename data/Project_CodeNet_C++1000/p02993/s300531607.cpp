#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  string s;
  cin >> s;
  if(s[0]==s[1] || s[1]==s[2] || s[2]==s[3]){
    cout << "Bad" << endl;
  }
  else{
    cout << "Good" << endl;
  }
  return 0;
}