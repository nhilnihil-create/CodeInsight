#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N,X;
cin>>N;
  string Ans="APPROVED";
rep(i,N){cin>>X;if(X%2==0){if((X%3)*(X%5)!=0){Ans="DENIED";break;}}}
  cout<<Ans<<endl;
}