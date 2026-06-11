#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,L;cin>>N>>L;
  int ideal_pie;
  for(int i=0;i<N;i++) ideal_pie +=L+i;//L+i-1+1
  vector<int> A(N);
  for(int i=0;i<N;i++) A.at(i)=ideal_pie-(L+i);
  vector<int> B(N);
  for(int i=0;i<N;i++) B.at(i)=abs(ideal_pie-A.at(i));
  int min_B=B.at(0);
  int Bx=0;
  for(int i=1;i<N;i++){
    if(min_B>B.at(i)){
      min_B=B.at(i);
      Bx=i;
    }
  }
  cout<<A.at(Bx)<<endl;
      
}
