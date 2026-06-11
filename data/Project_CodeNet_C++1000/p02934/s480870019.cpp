#include<bits/stdc++.h>
using namespace std;


int main() {
  cout << fixed << setprecision(10);
  int N;cin>>N;
  vector<double> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  double ans=0;
  double X;
  for(int i=0;i<N;i++){
    X=1/A.at(i);
    ans +=X;
  }
  double Ans=1/ans;
  cout<<Ans<<endl;
}


