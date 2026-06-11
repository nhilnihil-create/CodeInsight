#include<iostream>
using namespace std;

const long long MOD=1000000007;

int main() {
  int N,A,B,C,D;
  cin >> N >> A >> B >> C >> D;
  A--;
  B--;
  C--;
  D--;
  string S;
  cin >> S;
  int e=-1;
  if(A<B&&C<D||A>B&&C>D){
    e=1;
  }
  else{
  for(int i=B-1;i<min(C,D);i++){
    if(S.at(i)==S.at(i+1)&&S.at(i+1)==S.at(i+2)&&S.at(i)=='.')
      e=1;
  }
  }
  for(int i=A;i<max(C,D)-1;i++){
    if(S.at(i)==S.at(i+1)&&S.at(i)=='#')
      e=-1;
  }
  if(e==1){
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
}