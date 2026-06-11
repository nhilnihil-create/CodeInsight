#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,M;
  cin >> A >> B >> M;
  vector<int> a(A);
  vector<int> b(B);
  for(int i = 0; i<A;i++){
    cin >> a.at(i);
  }
  for(int j = 0; j<B; j++){
    cin >> b.at(j);
  }
  int ans = 200001;
  int sum;
  for(int i = 0; i<M; i++){
    int x,y,c;
    cin >> x >> y >> c;
    sum = a.at(x-1)+b.at(y-1)-c;
    ans = min(sum,ans);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  cout << min(ans,a.at(0)+b.at(0)) << endl;
}