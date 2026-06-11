#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> ac(N), wa(N);
  ac.assign(0, N);
  wa.assign(0, N);
  int p;
  string s;
  int ac_cnt =0, wa_cnt=0;
  for(int i=0; i<M; i++){
    cin >> p >> s;
    p--;
    if(s=="AC" && ac[p]==0){
      wa_cnt += wa[p];
      ac[p] = 1;
      ac_cnt++; 
    }
    
    wa[p]++;
    
  }
  
  
  cout << ac_cnt << " " << wa_cnt << endl;
  
  
 
  return 0;
}