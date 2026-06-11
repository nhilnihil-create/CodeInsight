#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
const int INF = 0x7fffffff;
using lll = long long;
using ull = unsigned long long;
using namespace std;


bool isPalindrome(string s){

  //if((s.size() % 2) != 1){
  //  return false;
  //}
  
  int n = s.size()/2;
  int ii;

  for(ii=0;ii<n;ii++){
    if(s[ii] != s[s.size()-ii-1]){
      return false;
    }
  }
  
  return true;
}

int main(){
  lll ii,jj,kk;
  vector<int> ret;

  string s;

  cin >> s;

  string first,last;
  int n = s.size();
  int start = (n+3)/2 - 1;
  first = "";
  last  = "";

  for(ii=0;ii<(n-1)/2;ii++){
    first += s[ii];
    last  += s[start+ii];
  }

  //cout << first << endl;
  //cout << last << endl;
  
  if(isPalindrome(first) && isPalindrome(last) && isPalindrome(s)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}
