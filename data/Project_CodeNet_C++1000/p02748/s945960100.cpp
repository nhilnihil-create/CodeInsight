#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,m;
  cin >> a >> b >> m;
  vector<int> A(a);
  vector<int> B(b);
  for (int i=0; i<a; i++) cin >> A[i];
  for(int j=0; j<b; j++) cin >> B[j];
  int ans = 0;
  int minA = *min_element(A.begin(), A.end());
  int minB = *min_element(B.begin(), B.end());
  ans = minA+minB;
  for(int k=0; k<m; k++){
    int a_ind,b_ind,c;
    cin >> a_ind >> b_ind >> c;
    int tmp;
    tmp = A[a_ind-1]+B[b_ind-1]-c;
    ans = min(ans,tmp);
  }  
  cout << ans << endl;
}