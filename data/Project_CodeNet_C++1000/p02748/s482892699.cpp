#include <bits/stdc++.h>
using namespace std;

int main() {
 int a,b,m;
  cin>>a>>b>>m;
  vector<int>aprice(a);
  vector<int>bprice(b);
  vector<vector<int>> data(m, vector<int>(3));
  for(int i=0;i<a;i++){
    cin>>aprice[i];
  }
  for(int i=0;i<b;i++){
    cin>>bprice[i];
  }
   for (int j = 0; j < m ; j++) {
      for (int k = 0; k < 3; k++) {
        cin >> data.at(j).at(k);
      }
    }
   int pp=aprice.at(data.at(0).at(0)-1)+bprice.at(data.at(0).at(1)-1)-data.at(0).at(2);
  for(int i=0;i<m;i++){
   
    int x=aprice.at(data.at(i).at(0)-1)+bprice.at(data.at(i).at(1)-1)-data.at(i).at(2);
    if(x <=pp){
      pp =x;
    }
  }
  sort(aprice.begin(),aprice.end());
  sort(bprice.begin(),bprice.end());
  int t=aprice[0]+bprice[0];
  if(t<=pp){
    pp=t;
  }
  cout<<pp<<endl;
  
}
