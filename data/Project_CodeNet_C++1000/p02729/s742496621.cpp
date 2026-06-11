#include<iostream>
using namespace std;
 
int main(){
  int N,M,res=0;
  cin >> N >> M;
  res = N*(N-1)/2+M*(M-1)/2;
  cout << res << endl;
}