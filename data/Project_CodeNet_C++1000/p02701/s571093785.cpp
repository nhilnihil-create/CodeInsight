#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<string>A(N);
  set<string>S;
  rep(i,N){
    cin>>A[i];
    S.insert(A[i]);
  }
  cout<<S.size()<<endl;
}