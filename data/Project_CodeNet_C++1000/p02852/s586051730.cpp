#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  string S;
  cin >> N >> M;
  cin >> S;
  int flag = 0;
  vector<int> result;
  for(int now = N;now > 0;now += 0){
    flag = 0;
    for(int a = min(M,now);a > 0;a -= 1){
      
      if(S[now - a] == '0'){
       now =  now - a;
        result.push_back(a); 
        flag = 1;
        break;
      }
 
    }
    if(flag == 0){
       break; 
      }
      
  }
  if(flag == 0){
    cout<<-1<<endl;
  }else{
    for(int a = result.size() - 1;a >= 0;a -= 1)cout<<result.at(a)<<" ";
  }
 
}