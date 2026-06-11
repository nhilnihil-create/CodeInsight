#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x; cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n,vector<int>(m));
  
  int min_money = 999999999;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= m; j++){
      if(j == 0)
        cin >> c.at(i);
      else
        cin >> a.at(i).at(j-1);
    }
  }
  
  for(int tmp = 0; tmp < (1 << 12); tmp++){
    vector<int> understand(m,0);
    bitset<12> s(tmp);
    int money = 0;
    
    for(int i = 0; i < n; i++){
      if(s.test(i)){
        money += c.at(i);
        for(int j = 0; j < m; j++){
          understand.at(j) += a.at(i).at(j);
        }
      }
    }
    
    bool achive = true;
    for(int i = 0; i < m; i++) 
      if(understand.at(i) < x) achive = false;
    
    if(achive){
      if(min_money > money)
        min_money = money;
    }
    money = 0;
  }
  if(min_money == 999999999)
    cout << -1;
  else
  	cout << min_money;
  
}