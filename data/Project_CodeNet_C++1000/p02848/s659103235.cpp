#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  int A=S.size();
  for(int i=0;i<A;i++){
    if(S.at(i)+N<='Z'){
      S.at(i)+=N;
    }
    else{
      S.at(i)+=N-26;
    }
    cout << S.at(i);
  }
  cout << endl;
}
  