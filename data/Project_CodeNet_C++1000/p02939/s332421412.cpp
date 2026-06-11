#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll z=0;

int main() {
  string S,p="";
  cin >> S;
  string str="";
  int ans=0;
  for(int i=0;i<S.size();i++){
    str +=S[i];
    if(p!=str){
      p=str;
      ans++;
      str="";
    }
  }
  cout << ans << endl;
}