#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define MODA 1000000007 

int main() {
    ll ans = 0;
    int N;
    ll A[100001] ={}, sum = 0;
    cin >> N; 
    REP(i, N){
      cin >> A[i];
      sum = sum ^ A[i];
    } 
    //cout << bitset<6>(~sum) << endl;
    REP(i, N){
        A[i] = A[i] & (~sum);
        //cout << bitset<6>(A[i]) << endl;
    }
    int rank = 0;
    ll now;
    bool flag;
    for(int i = 59; i >=0; i-- ){
      ll ch = (ll) 1 << (ll)i;
      //cout << bitset<60>(ch) << endl;
      flag = false;
      for(int j=rank; j<N; j++){
        if(ch & A[j]){
          now = A[j];
          swap(A[j], A[rank]);
          flag = true;
          break;
        }
      }
      if(flag){
        REP(j, N){
          if(j != rank && (A[j] & ch)){
            A[j] = A[j] ^ now;
          }
        }
        rank++;
      }
    }
    REP(i, N){
      //cout << bitset<6>(A[i]) << endl;
      ans = ans ^ A[i];
    }
    ans = ans * 2 + sum;
    cout << ans << endl;
}