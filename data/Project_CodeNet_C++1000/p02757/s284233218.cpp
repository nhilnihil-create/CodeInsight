#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,P;
  cin>>N>>P;
  string S;
  cin>>S;
  int64_t Z=0,A=0,B=1;
  if(P==2||P==5){
    for(int64_t i=0;i<N;i++){
      int a=S[i]-'0';
      if(!(a%P)){
        Z+=i+1;
      }
    }
  }
  else{
    map<int,int64_t> m;
    m[0]=1;
    reverse(S.begin(),S.end());
    for(int i=0;i<N;i++){
      A+=(S[i]-'0')*B;
      A%=P;
      B*=10;
      B%=P;
      m[A]++;
      Z+=m[A];
    }
    Z-=N;
  }
  cout<<Z<<endl;
}