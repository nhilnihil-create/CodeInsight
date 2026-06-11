#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  int n; cin>>n;
  vector<int>A(n+1);
  A[0] = 0;
  A[1] = 0;
  for (int i=1; i<n; i++) cin>>A[i];
  vector<int>Count(n+1);
  for (int i=1; i<=n; i++){
    int a = A[i];
    Count[a]++;
  }
  for (int i=1; i<=n; i++) cout << Count[i] << endl;
}