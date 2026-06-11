#include<bits/stdc++.h>
using namespace std;

int main (){
  int A,B,M;
  cin >> A>>B>>M;
  vector<int> a(A),b(B),sum(M);
  
  for (int i=0;i<A;i++){
    cin >> a[i];
  }
  for (int i=0;i<B;i++){
    cin >> b[i];
  }
  
  for (int i=0;i<M;i++){
    int x,y,c;
    cin >> x >> y >> c;
    sum[i] = a[x-1]+b[y-1]-c;
  }
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(sum.begin(),sum.end());
  
  cout << min(a[0]+b[0],sum[0]) << endl;
}