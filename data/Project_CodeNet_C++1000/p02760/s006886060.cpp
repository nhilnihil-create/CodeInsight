#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int A[3][3];
  rep(i,3)rep(j,3) cin>>A[i][j];
  int N,b[N];cin>>N;
  rep(i,N) cin>>b[i];
  
  int a=0,p=0,c=0;
  rep(k,N){
    if(A[0][0]==b[k]) a=1;
    if(A[0][1]==b[k]) p=1;
    if(A[0][2]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }
  
  a=0,p=0,c=0;
  rep(k,N){
    if(A[1][0]==b[k]) a=1;
    if(A[1][1]==b[k]) p=1;
    if(A[1][2]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }
  
  a=0,p=0,c=0;
  rep(k,N){
    if(A[2][0]==b[k]) a=1;
    if(A[2][1]==b[k]) p=1;
    if(A[2][2]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }

  a=0,p=0,c=0;
  rep(k,N){
    if(A[0][0]==b[k]) a=1;
    if(A[1][0]==b[k]) p=1;
    if(A[2][0]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }
  
  a=0,p=0,c=0;
  rep(k,N){
    if(A[0][1]==b[k]) a=1;
    if(A[1][1]==b[k]) p=1;
    if(A[2][1]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }
  
  a=0,p=0,c=0;
  rep(k,N){
    if(A[0][2]==b[k]) a=1;
    if(A[1][2]==b[k]) p=1;
    if(A[2][2]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }
  
  a=0,p=0,c=0;
  rep(k,N){
    if(A[0][0]==b[k]) a=1;
    if(A[1][1]==b[k]) p=1;
    if(A[2][2]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }

  a=0,p=0,c=0;
  rep(k,N){
    if(A[0][2]==b[k]) a=1;
    if(A[1][1]==b[k]) p=1;
    if(A[2][0]==b[k]) c=1;
  }
  if(a+p+c==3){
    cout << "Yes" << endl;
    goto step1;
  }
  else goto step2;
 
  step2: cout << "No" << endl;
  step1: return 0;
}