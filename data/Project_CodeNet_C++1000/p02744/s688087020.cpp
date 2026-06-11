#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<string> a;
int c(string s) {
  vector<int> num(26,0);
  for(int i = 0; i < s.size(); i++) {
    num[s[i] - 'a']++;
  }
  int res = 0;
  for(int i = 0; i < 26; i++) {
    if(num[i]) res++;
  }
  return res;
}


int main() {
  int n;
  cin >> n;

  a.push_back("a");
  for(int i = 1; i < n; i++) {
    int N = a.size();
    vector<string> tmp;
    for(int j = 0; j < N; j++) {
      int t = c(a[j]);
      for(int k = 0; k <= t; k++) {
	string T = a[j] + (char)(k + 'a');
	tmp.push_back(T);
      }
    }
    a = tmp;
  }

  // for(int i = 0; i < a.size(); i++) cout << a[i] << endl;
  
  sort(a.begin(),a.end());

  for(int i = 0; i < a.size(); i++) cout << a[i] << endl; 
  
}

  
