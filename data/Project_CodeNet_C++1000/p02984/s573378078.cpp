#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll N; cin >> N;
  ll A[N],B[N];
  ll sum = 0;
  ll exc = 0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(i%2==1) exc += A[i];
    sum += A[i];
  }
  B[0] = sum - 2*exc;
  cout << B[0] << " ";
  for(int i=1;i<N;i++){
    B[i] = (A[i-1] - B[i-1]/2)*2;
    cout << B[i] << " ";
  }
}
