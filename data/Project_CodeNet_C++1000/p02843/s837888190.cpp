#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  cout<<(N/100*5<N%100? 0:1)<<endl;
}