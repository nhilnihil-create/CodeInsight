#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> a(100);
  
  int cnt=0;
  while(N!=0){
    a[cnt]=(N-1)%26;
    N=(N-1-a[cnt])/26;
    cnt++;
  }
  vector<char> alpha={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  for(int i=cnt-1;i>=0;i--){
    cout << alpha[a[i]];
  }
}
