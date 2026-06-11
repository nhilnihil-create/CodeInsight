#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  int ans = b.size();
  for (int i=0;i <= (a.size()-b.size());i++){
    int dd=0;
    for(int j=0;j < b.size();j++){
      if(a.at(i+j)!=b.at(j)) dd++;
    }
    ans = min(ans,dd);
  }
  cout << ans << endl;
}
