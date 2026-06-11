#include <bits/stdc++.h>
using namespace std;

int main() {
  int T,R;
  cin >> T >> R;
  vector<int>data(T);
  for(int i=0;i<T;i++){
    cin >> data.at(i);
  }
  vector<bool>res(T,true);
  for(int i=0;i<R;i++){
    int a,b;
    cin >> a >> b;
    if(data.at(a-1)==data.at(b-1)){
      res.at(a-1)=false;
      res.at(b-1)=false;
    }else if(data.at(a-1)>data.at(b-1)){
      res.at(b-1)=false;
    }else{
      res.at(a-1)=false;
    }
  }
  int ans=0;
  for(int i=0;i<T;i++){
    if(res.at(i)) ans++;
  }
  cout << ans << endl;
}