#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 

int main() {
  int n;
  cin >> n;
  
  string s;
  map<string,long long> m{};
  
  for(int i = 0;i<n;i++){
    cin >> s;
    sort(s.begin(), s.end());
    
    if(m.count(s) == 0){
      m.insert(make_pair(s,1));
    }else{
      m[s] = m[s] + 1;
    }
  }
  long long res = 0;
  for( auto i = m.begin(); i != m.end() ; ++i ) {
    if(i->second >1){
      //cout << i->second << " "<<i->second<< endl;
      res += (i->second)*(i->second-1)/2;
    }
  }
 

  
  cout << res;
}
