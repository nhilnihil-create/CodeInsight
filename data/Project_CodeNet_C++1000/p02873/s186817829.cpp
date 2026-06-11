#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  vector<int64_t> cnts;
  int64_t cnt= 0;
  char c_prev= ' ';
  for(size_t i=0; i<S.size(); i++){
    char c_tmp= S.at(i);
    if(c_prev != c_tmp){
      cnts.emplace_back(cnt);
      cnt= 0;
    }

    cnt++;
    c_prev= c_tmp;
  }
  cnts.emplace_back(cnt);
  cnts.emplace_back(0);

  int64_t ans= 0;
  size_t id_peak_mod2= (S.at(0)=='>') ? 1
                                      : 0;
  for(size_t i=1; i< cnts.size(); i++){
    ans+= cnts.at(i)*(cnts.at(i)-1)/ 2;
    if(i%2==id_peak_mod2){
      ans+= max(cnts.at(i-1), cnts.at(i));
    }
  }

  cout << ans << endl;
}