#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<ll> A(N),B(N);

  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  if( N % 2 == 1){
    int mid = N / 2;
    cout << B[mid] - A[mid] + 1 << endl;
  } else { 
    int mid1 = N/2-1;
    int mid2 = N/2;

    ll min_val = (A[mid1] + A[mid2]);
    ll max_val = (B[mid1] + B[mid2]);

    cout << max_val - min_val + 1 << endl;

  }

}
