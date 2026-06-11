#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector< int > z_algorithm(const string &s) {
  vector< int > prefix(s.size());
  for(int i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while(i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) s.size();
  return prefix;
}

int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        vector<int> Z = z_algorithm(s.substr(i));
        for(int j = 0; j < s.length() - i; j++){
            if (Z[j] <= j)ans = max(ans, Z[j]);
        }
    }
    cout << ans << endl;
    return 0;
}