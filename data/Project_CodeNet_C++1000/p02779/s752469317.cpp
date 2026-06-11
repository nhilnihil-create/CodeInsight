#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int,int> m;
  bool ok=1;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(m[x]!=0){
      ok=0;
    }
    m[x]++;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}
