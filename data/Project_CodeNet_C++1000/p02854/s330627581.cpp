#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  ll length=0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    length+=A[i];
  }
  ll left=0;
  ll dif=length;
  for(int i=0; i<N; i++){
    left+=A[i];
    ll temp=abs(left-length+left);
    if(dif>temp){
      dif=temp;
    }
  }
  cout << dif <<endl;
}