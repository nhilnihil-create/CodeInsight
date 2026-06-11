#include <iostream>
#include <vector>

using namespace std;

bool is_valid(const string &s, int l, int r){
  for(int i=l;i<r-1;i++){
    if(s[i] == '#' && s[i+1] == '#')
      return false;
  }
  return true;
}

bool is_otable(const string &s, int l, int r){
  for(int i=l;i<r-2;i++){
    bool ok = true;
    for(int j=0;j<3;j++){
      if(s[i+j] == '#')ok = false;
    }
    if(ok)return true;
  }
  return false;
}

int main(){
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  a--;b--;c--;d--;
  bool f = is_valid(s, a, max(c, d) + 1);
  bool g = c < d | is_otable(s, b - 1, min((int)s.length(), d + 2));
  if(f & g)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  cerr << f << " " << g << endl;
}
