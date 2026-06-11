#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  long long count=0;
  string S;
  cin >> N >> S;
  long long R=0,G=0,B=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='R'){
      R++;
    }
    else if(S.at(i)=='G'){
      G++;
    }
    else{
      B++;
    }
  }
  for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      int k=2*j-i;
      if(k<=j || N-1<k){
        continue;
      }
      if(S.at(i)==S.at(j) || S.at(j)==S.at(k) || S.at(k)==S.at(i)){
        continue;
      }
      count++;
    }
  }
  cout << R*G*B-count << endl;
}