#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int N,M,Q;
vector<int> A;

bool next() {
  int i;
  for (i=A.size()-1;i>=0 && A[i]>=M;i--) {}
  if (i<0) {
    return false;
  } else {
    A[i]++;
    for (int j=i+1;j<A.size();j++) {
      A[j] = A[i];
    }
    return true;
  }
}

int main() {
  int i;
  cin>>N>>M>>Q;
  vector<vector<int>> a(Q, vector<int>(4));
  for (i=0;i<Q;i++) {
    cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
  }

  A = vector<int>(N,1);
  int ans = 0;
  do {
    int score = 0;
    for (i=0;i<Q;i++) {
      if (A[a[i][1]-1]-A[a[i][0]-1] == a[i][2]) score += a[i][3];
    }
    ans = max(ans, score);
  } while (next());

  cout<<ans<<endl;
  return 0;
}
