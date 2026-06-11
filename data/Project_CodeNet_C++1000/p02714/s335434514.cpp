#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

int main(){
  int64_t n;
  cin >> n;
  string s;
  cin >> s;
  int64_t r_count = count(s.begin(), s.end(), 'R');
  int64_t g_count = count(s.begin(), s.end(), 'G');
  int64_t b_count = count(s.begin(), s.end(), 'B');
  int duplicate = 0;
  for(int64_t i = 0; i < n; ++i){
    for(int64_t j = 1; i+j+j <= n-1; ++j){
      set<char> colors;
      if(i+j+j >= n)continue;
      colors.insert(s[i]);
      colors.insert(s[i+j]);
      colors.insert(s[i+j+j]);
      if(colors.size() == 3)duplicate++;
    }
  }
  cout << r_count*g_count*b_count - duplicate << endl;

  return 0;
}

