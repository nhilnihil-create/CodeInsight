#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,M;
  cin>>A>>B>>M;
  vector<int>a(A);
  vector<int>b(B);
  for(int i=0;i<A;i++){
    cin>>a.at(i);
  }
  for(int i=0;i<B;i++){
    cin>>b.at(i);
  }
  vector<int>x(M);
  vector<int>y(M);
  vector<int>c(M);
  for(int i=0;i<M;i++){
    cin>>x.at(i)>>y.at(i)>>c.at(i);
  }
  vector<int>answer(M+1);
  for(int i=0;i<M;i++){
    answer.at(i)=a.at(x.at(i)-1)+b.at(y.at(i)-1)-c.at(i);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  answer.at(M)=a.at(0)+b.at(0);
  sort(answer.begin(),answer.end());
  cout<<answer.at(0)<< endl;
}
  