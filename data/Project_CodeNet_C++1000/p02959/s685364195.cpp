#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N+1),B(N);
  for(int i=0;i<N+1;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<N;i++){
    cin >> B.at(i);
  }
  long long count=0;
  for(int i=0;i<N;i++){
    int C=min(A.at(i),B.at(i));
    A.at(i)-=C;
    count+=C;
    B.at(i)-=C;
    int D=min(A.at(i+1),B.at(i));
    A.at(i+1)-=D;
    count+=D;
    B.at(i)-=D;
  }
  cout << count << endl;
}  