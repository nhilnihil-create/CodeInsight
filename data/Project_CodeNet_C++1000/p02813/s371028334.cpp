#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,i;
  ll P[10],Q[10];
  ll ord[10];
  bool x;
  cin >> N;
  ll a,b;
  for(i=0;i<=N-1;i++)
    cin >> P[i];
  for(i=0;i<=N-1;i++)
    cin >> Q[i];
  for(i=0;i<=N-1;i++)
    ord[i] = i+1;
  for(a=0;a<=100000000;a++){
    x = true;
    for(i=0;i<=N-1;i++)
      if(ord[i]!=P[i]) x = false;
    next_permutation(ord,ord+N);
    if(x) break;
  }
  for(i=0;i<=N-1;i++)
    ord[i] = i+1;
  for(b=0;b<=100000000;b++){
    x = true;
    for(i=0;i<=N-1;i++)
      if(ord[i]!=Q[i]) x = false;
    next_permutation(ord,ord+N);
    if(x) break; 
  }
  cout << abs(a-b);
}