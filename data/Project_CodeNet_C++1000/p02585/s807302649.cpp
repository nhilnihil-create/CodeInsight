#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll min_v = -10000000000;
 
int p[5050];
int c[5050];
ll rui[5050];
int visited[5050];
 
ll ss(int j, int k)
{
  ll mx = min_v;
  for( int i=0;i<j;i++){
    for(int kk=0; kk<k; kk++){
      int l = i + kk + 1;
      ll v;
      if( l > j ){
        v = rui[l-j] + rui[j] - rui[i];
      } else {
        v = rui[l] - rui[i];
      }
      if( v > mx ) mx = v;
    }
  }
  return mx;
}
 
int main()
{
  int n,k;    cin >> n >> k;
  
  for(int i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
  }
  for(int i=0;i<n;i++){
    cin >> c[i];
  }
  
  for(int i=0;i<5050;i++){ rui[i] = visited[i] = 0; }
  
  int st = 0; ll mx = min_v;
  
  while( st < n ){
    while( st < n && visited[st] != 0 ){ st++; }
    if( st >= n ){ break; }
    
    int i = st, j = 0;
    rui[0] = 0;
    while( visited[i] == 0 ){
      visited[i] = 1;
      int n_i = p[i];
      rui[1+j] = rui[j] + c[n_i];
      i = n_i;
      j++;
    }
    
    ll v = min_v;
    if( rui[j] > 0 ){
      int m1 = k % j;
      int m2 = (k - m1)/j;
      ll v1 = min_v;
      if( m1 > 0 ) v1 = ss(j,m1) + m2 * rui[j] ;
      ll v2 = min_v;
      if( m2 > 0 ) v2 = ss(j,j) + rui[j] * ( m2 - 1 );
      v = max(v1,v2);
    } else {
      int m1 = ( k >= j ? j : k );
      v = ss(j,m1);
    }
    if( v > mx ) mx = v;
  }
  
  cout << mx << endl;
  
  return 0;
  
}