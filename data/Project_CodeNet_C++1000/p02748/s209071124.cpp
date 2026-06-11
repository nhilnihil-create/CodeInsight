#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,m;
  cin >> a >> b >> m;
  vector<int>price_a(a);
  vector<int>price_b(b);
  for(int i=0;i<a;i++){
    cin >> price_a.at(i);
  }
  for(int i=0;i<b;i++){
    cin >> price_b.at(i);
  }
  vector<int> copy_a=price_a;
  vector<int> copy_b=price_b;
  sort(copy_a.begin(),copy_a.end());
  sort(copy_b.begin(),copy_b.end());
  int ans=copy_a.at(0)+copy_b.at(0);
  for(int i=0;i<m;i++){
    int x,y,c;
    cin >> x >> y >> c;
    int num=price_a.at(x-1)+price_b.at(y-1)-c;
    ans=min(ans,num);
  }
  cout << ans << endl;
}
    