#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

typedef long long lli;

string str;
int L;
map<lli, int> used;

lli stol(string& s){
  lli r = 1, res = 0;
  for(int i=L-1;i>=0;i--,r*=10) res += (s[i] - '0') * r;
  return res;
}

string ltos(lli n){
  string res;
  for(int i=0;i<L;i++,n/=10) res += (char)(n % 10) + '0';
  reverse(res.begin(), res.end());
  return res;
}

main(){
  while(cin >> str >> L){
    if(str == "0" && L == 0) break;
    used.clear();
    for(int i=str.size();i<L;i++) str += '0';
    int p = 0;
    used[stol(str)] = p++;
    while(1){
      lli a, b, c;
      sort(str.begin(), str.end());
      b = stol(str);
      reverse(str.begin(), str.end());
      a = stol(str);
      c = a - b;
      if(used.find(c) != used.end()){
        cout << used[c] << ' ' << c << ' ' << p - used[c] << endl;
        break;
      }
      used[c] = p++;
      str = ltos(c);
    }
  }
}