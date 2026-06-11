#include <bits/stdc++.h>
using namespace std;

int main() {
  long H,W,M;
  cin>>H>>W>>M;
  vector<long>K(M);
  vector<long>O(M);
  long h=H+1;
  long w=W+1;
  int m=max(h,w);
  vector<long>A(m,0);
  vector<long>B(m,0);
  vector<long>a(m,0);
  vector<long>b(m,0);
  vector<long>D(m,0);
  vector<long>d(m,0);
  vector<long>Z(m,0);
  vector<long>z(m,0);
  vector<long>Y(m,0);
  vector<long>y(m,0);
  for(long i=0;i<M;i++){
    cin>>K[i]>>O[i];
    A[K[i]]++;
    B[O[i]]++;
    a[K[i]]++;
    b[O[i]]++;
    D[K[i]]++;
    d[O[i]]++;
    Z[K[i]]++;
    z[K[i]]++;
    Y[O[i]]++;
    y[O[i]]++;
  }
  long C=0;
  long c=0;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(long i=0;i<m;i++){
    if(a[0]==D[i]){
      c=i;
      break;
    }
  }
  for(long i=0;C<a[0];i++){
    if(K[i]==c){
      b[O[i]]--;
      C++;
    }
  }
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  int ANS=a[0]+b[0];
  long E=0;
  sort(B.begin(),B.end());
  reverse(B.begin(),B.end());
  for(long i=0;i<m;i++){
    if(B[0]==d[i]){
      c=i;
      break;
    }
  }
  for(int i=0;E<B[0];i++){
    if(O[i]==c){
      A[K[i]]--;
      E++;
    }
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  int ans=A[0]+B[0];
  int Last=max(ANS,ans);
  
  //ここから折り返し
  
  long F=0;
  long f=0;
  sort(z.begin(),z.end());
  reverse(z.begin(),z.end());
  for(long i=m-1;i>=0;i--){
    if(z[0]==D[i]){
      f=i;
      break;
    }
  }
  for(long i=0;F<z[0];i++){
    if(K[i]==f){
      y[O[i]]--;
      F++;
    }
  }
  sort(y.begin(),y.end());
  reverse(y.begin(),y.end());
  int SNA=z[0]+y[0];
  long G=0;
  sort(Y.begin(),Y.end());
  reverse(Y.begin(),Y.end());
  for(long i=m-1;i>=0;i--){
    if(Y[0]==d[i]){
      f=i;
      break;
    }
  }
  for(int i=0;G<Y[0];i++){
    if(O[i]==f){
      Z[K[i]]--;
      G++;
    }
  }
  sort(Z.begin(),Z.end());
  reverse(Z.begin(),Z.end());
  int sna=Z[0]+Y[0];
  int last=max(SNA,sna);
  
  cout<<max(Last,last)<<endl;
}