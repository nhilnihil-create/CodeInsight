#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans=0;
  for(int i=1;i<=N;i++){
    string t = to_string(i);
    if(t.length()%2==0){
      continue;
    }else{
      ans +=1;
    }
  }
      cout << ans << endl;
}