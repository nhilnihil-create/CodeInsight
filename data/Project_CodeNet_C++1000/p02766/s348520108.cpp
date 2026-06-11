#include <bits/stdc++.h>
using namespace std;

int main() {
int N,K,Ans=1;
cin>>N>>K;
  while(N/K>0){Ans++;N=N/K;}
  cout<<Ans<<endl;
}