#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

vector<pair<char, int>> RunLengthEncoding(string data) {
    int n = data.size();
    vector<pair<char, int>> ret;
    char c = data[0];
    int num = 1;
    for(int i=1; i<n; i++) {
        if(data[i] == c) {
            num++;
        }else{
            ret.push_back({c, num});
            c = data[i];
            num = 1;
        }
    }
    ret.push_back({c, num});
    return ret;
}

int main() {
  string s; cin >> s;
  long long k; cin >> k;

  auto x = RunLengthEncoding(s);
  long long cnt = 0;
  int l = x.size();
  if (l == 1) {
    long long a = x[0].second*k / 2;
    cout << a << endl;
    return 0;
  }
  for(int i=0; i<l; i++) {
    cnt += x[i].second / 2;
  }
  long long d = 0;
  if (x[0].first == x[l-1].first) {
    d = x[0].second / 2 + x[l-1].second / 2;
    d -= (x[0].second + x[l-1].second) / 2;
    d *= (k-1);
  }
  cout << k * cnt - d << endl;
 
  return 0;
}

// EOF