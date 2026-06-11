#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,count=0;
  cin >> N;
  map<string,int> S;
  for(int i=0;i<N;i++){
    string A;
    cin >> A;
    if(!S.count(A)){
      S[A]=1;
      count++;
    }
  }
  cout << count << endl;
}
  
  