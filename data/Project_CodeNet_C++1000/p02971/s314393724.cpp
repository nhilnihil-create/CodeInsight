#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N,0);
  for(int i = 0; i< N; i++) {
    cin >> a.at(i);
    b.at(i) += a.at(i);
  }
  sort(b.begin(),b.end());
  int p = b.at(N-1);
  int q;
  if(b.at(N-2)!=p){
    q = b.at(N-2);
  }
  else{
    q = b.at(N-1);
  }
  
  for(int i = 0; i<N; i++){
    if(a.at(i)==p){
      cout << q << endl;
    }
    else{
      cout << p << endl;
    }
  }
}