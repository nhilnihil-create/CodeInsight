#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b,m,ans=100000000000;
  cin >> a >> b >> m;
  int64_t A[a],B[b];
  for(int64_t i=0;i<a;i++)cin >> A[i];
  for(int64_t j=0;j<b;j++)cin >> B[j];
  for(int64_t i=0;i<m;i++){
    int64_t x,y,c;
    cin >> x >> y >> c;
    ans=min(ans,A[x-1]+B[y-1]-c);
  }
  sort(A,A+a);
  sort(B,B+b);
  if(ans<A[0]+B[0])cout << ans << endl;
  else cout << A[0]+B[0] << endl;
}