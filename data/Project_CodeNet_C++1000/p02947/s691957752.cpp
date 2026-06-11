#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  long cnt = 0;
  map<string,long> a;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    sort(s.begin(), s.end());
    //cout << s << endl;
    if(a.count(s)){
      cnt += a[s];
      a[s]++;
    }
    else
      a[s] = 1;
  }
  cout << cnt;
}
      