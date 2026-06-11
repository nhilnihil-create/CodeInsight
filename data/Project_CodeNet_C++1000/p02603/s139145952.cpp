#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  long long res=1000;
  for(int i=0;i<N-1;i++){
    int S=A.at(i);
    int T=A.at(i+1);
    if(S<T){
      long long C=res/S;
      res%=S;
      res+=C*T;
    }
  }
  cout << res << endl;
}
    