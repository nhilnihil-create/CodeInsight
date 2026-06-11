#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,M; cin>>A>>B>>M;
  vector<int> a(A),b(B),x(M),y(M),c(M);
  for(int i=0;i<A;i++)cin>>a[i];
  for(int i=0;i<B;i++)cin>>b[i];
  int tmp,mini=1e6;
  for(int i=0;i<M;i++){
    cin>>x[i]>>y[i]>>c[i];
    tmp=a[x[i]-1]+b[y[i]-1]-c[i];
    //cout <<x[i]<<" "<<a[x[i]]<<" "<<y[i]<<" "<<b[y[i]]<<" "<<c[i]<<endl;
    if(mini>tmp)mini=tmp;
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(mini>a[0]+b[0]) mini=a[0]+b[0];
  cout <<mini<<endl;
}