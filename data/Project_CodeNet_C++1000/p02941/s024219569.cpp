#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void DC(){ cout << - 1 << endl;}

int main(){
 int N; cin >> N; ll cnt = 0 ;
  vector<ll> A(N); vector<ll> B(N);
  priority_queue<pair<ll,int>> Q;
  for(int i = 0; i < N; i++){ cin >> B[i];}
  for(int j = 0; j < N; j++){ cin >> A[j]; Q.push(make_pair(A[j],j));}
  
  while(!Q.empty()){
    ll p = Q.top().first;
    int b = Q.top().second; Q.pop();
    if( p == B[b]){ continue;}
    if( p < B[b]){ DC(); return 0;}
    
    int a, c;
    if( b == 0){ a = N - 1; } else{ a = b - 1;}
    if( b == N - 1){ c = 0;} else{ c = b + 1;}
    
    if( A[b] < A[a] + A[c] ){ DC(); return 0;}
     
    if( A[b] % ( A[a] + A[c]) >= B[b]){ 
      cnt += A[b] / (A[a] + A[c]); 
      Q.push(make_pair( A[b] % ( A[a] + A[c]), b)); A[b] = A[b] % ( A[a] + A[c]);}
     
     else{
         ll res = A[b] - (( A[b] - B[b]) / ( A[a] + A[c] )) * ( A[a] + A[c]);
       
         if( res == A[b]){ DC(); return 0;}
         
         cnt += (A[b] - B[b])/( A[a] + A[c]); 
         Q.push(make_pair(res, b));
         A[b] = res;}
           
       
             }
             
             cout << cnt << endl; return 0;}
             
    
    