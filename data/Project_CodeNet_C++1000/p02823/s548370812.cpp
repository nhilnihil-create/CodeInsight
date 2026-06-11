#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,A,B;
  
  cin >> N >> A >> B;
  
  if((B-A)%2==0){
    cout << (B-A)/2 << endl;
  }else{
    if(A-1<N-B){
     cout << A+(B-A-1)/2 << endl;
    }else{
      cout << (N-B)+1+(B-A-1)/2 << endl;
    }
  }
  
}