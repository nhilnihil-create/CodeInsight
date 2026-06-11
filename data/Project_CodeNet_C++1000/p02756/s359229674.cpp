#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 

int main() {
  int q;
  string s;
  cin >> s >> q;
  
  
  deque<string> d;
  string t;
  for(int i = 0; i< s.size();i++){
    t = s[i];
    d.push_back(t);
  }
  
  int flg = 0;
  int tmp;
  int f;

  for (int i=0; i<q; i++){
    cin >> tmp;
    if(tmp == 1){
      flg = (flg+1)%2; 
    }else{
      cin >> f >> s;
      if((flg == 0 && f == 1) || (flg == 1 && f == 2)){
        d.push_front(s);
      }else{
        d.push_back(s);
      }
    }
  }
  if(flg == 0){
    while(!d.empty()){
      cout << d.front();
      d.pop_front();
    }
  }else{
    while(!d.empty()){
      cout << d.back();
      d.pop_back();
    }
  } 
}