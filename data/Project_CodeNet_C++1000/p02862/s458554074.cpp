#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1000000007;
int a(int A,int B){
  if(B==0)
    return 1;
  if(B%2==1)
    return a(A,B-1)*A%M;
  int C=a(A,B/2);
  return C*C%M;
}
int b(int A,int B){
  int C=1;
  for(int i=A;i<=B;i++)
    C=C*i%M;
  return C;
}
signed main(){
  int X,Y;
  cin>>X>>Y;
  if((X+Y)%3!=0 || X*2<Y || Y*2<X){
    puts("0");
    return 0;
  }
  int A=X-(X+Y)/3,B=Y-(X+Y)/3;
  cout<<b(B+1,A+B)*a(b(1,A)%M,M-2)%M<<endl;
}