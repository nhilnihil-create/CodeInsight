#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  string s,t; cin >> s >> t;
  int s_len = 0, t_len = 0;
  for(int i = 0; i < 2 * n; i++){
    if(i % 2 == 0){
      cout << s.at(s_len);
      s_len++;
    }
    else{
      cout << t.at(t_len);
      t_len++;
    }
  }     
  
}