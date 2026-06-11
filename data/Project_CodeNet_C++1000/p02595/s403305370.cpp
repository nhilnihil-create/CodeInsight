#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,d;
  cin >> n >> d;
  vector<double> x(n),y(n);
  int ans=0;
  for(int i=0;i<n;i++){
    cin >> x.at(i) >> y.at(i);
  }
  for(int i=0;i<n;i++){
    double dis=sqrt(x.at(i)*x.at(i)+y.at(i)*y.at(i));
    if(dis<=d){
      ans++;
    }
  }
  cout << ans;
}
