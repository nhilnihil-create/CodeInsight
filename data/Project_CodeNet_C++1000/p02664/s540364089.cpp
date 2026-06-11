#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin >> s;
  int n = s.length();
  for(int i = 0; i < n; i++){
    if(s[i] == '?'){
      s[i] = 'D';
    }
  }
  cout << s << endl;
  return 0;
}