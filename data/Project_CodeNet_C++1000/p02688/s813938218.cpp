#include <string>
#include <bits/stdc++.h>
#define For(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N,K,d,A;
  cin>>N>>K;
  vector<int>sunuke(N);
  for(int i=0;i<K;i++){
    cin>>d;
    for(int j=0;j<d;j++){
      cin>>A;
      sunuke.at(A-1)++;
    }
  }
  int cou=0; 
  for(int l=0;l<N;l++){
    if(sunuke.at(l)==0){
      cou++;
    }
  }
  cout<<cou<<endl;
}