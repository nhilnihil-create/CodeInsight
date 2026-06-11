#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
  
  ll N,M,V,P; cin >> N >> M >> V >> P;
  
  
  vector<ll> A(N);
  
  for(ll i = 0; i < N; i++){ cin >> A[i];}
  
  sort(A.rbegin(),A.rend());
  
  ll left = -1; ll right = N;
  
  while( right-left > 1 ){ 
    
    
    ll mid = (left+right)/2;
    
    if( mid < P ){ left = mid; continue;} 
    if( A[mid]+M < A[P-1] ){ right = mid; continue;}
    
    // 以下、それ以外の時
    
    ll posts = M*(P+(N-1-mid) );
    
    for(ll i = P-1; i < mid; i++){ 
      
      posts += max(0LL, A[mid]+M-A[i]);
      
    }
    
    if( posts < M*V){ right = mid;}
    else{ left = mid;}
    
  }
  
  // A[0],,,A[left]までが条件を満たす
  
  cout <<  left + 1 << endl;
  
  return 0;
} 
   