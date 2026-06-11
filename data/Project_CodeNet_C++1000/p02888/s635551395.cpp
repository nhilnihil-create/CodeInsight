#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  int N; cin >> N;
  int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A,A+N);
  int ans = 0;
  for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      int num = A[i]+A[j];
      int x = N;
      if(A[N-1]>=num){
        x = lower_bound(A,A+N,num)-A;
      }  
      ans += x-j-1;
    }
  }
  cout << ans << endl;
}