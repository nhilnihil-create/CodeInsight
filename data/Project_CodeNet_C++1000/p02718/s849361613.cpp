#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  long long SUM=0;
  cin >> n>>m;
  vector<int> line(n);
  for(int i=0;i<n;i++){
    cin >> line[i];
    SUM+=line[i];
  }
  sort(line.begin(), line.end());
  reverse(line.begin(), line.end());
  for(int i = 0;i < m;i++){
    if(line[i] < (double)SUM / (4*m)){
      cout<<"No"<<'\n';
      return 0;
    }
  }
    cout<<"Yes"<<'\n';
}
