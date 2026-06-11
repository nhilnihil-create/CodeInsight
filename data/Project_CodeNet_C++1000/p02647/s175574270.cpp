#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll N1097 = 1000000007LL;

ll N, K;
ll A[1000000];
ll d[1000000];
int main(){
  cin >> N >> K;
  for(ll i=0;i<N;i++){
    scanf("%ld", &A[i]);
  }
  //
  for(ll l=0;l<K;l++){
    for(ll i=0;i<=N;i++){
      d[i] = 0LL;
    }
    for(ll i=0;i<N;i++){
      ll a = A[i];
      d[max(0LL, i-a)] += 1;
      d[min(N, i+a+1)] -= 1;
    }
    ll tmp = 0;
    for(ll i=0;i<N;i++){
      tmp += d[i];
      A[i] = tmp;
    }
    int f=1;
    for(ll i=0;i<N;i++){
      if(A[i]!=N){
        f=0;
        break;
      }
    }
    if(f){
      break;
    }
  }
  for(ll i=0;i<N;i++){
    printf("%d ", A[i]);
  }

}


