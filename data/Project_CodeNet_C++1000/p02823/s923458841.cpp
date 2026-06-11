#include<iostream>
using namespace std;

int main(){
  long long N, A, B;
  cin >> N >> A >> B;
  
  long long ans=N+1;
  if(A%2 == B%2){
    ans = abs(A-B)/2;
    cout << ans << endl;
    
    return 0;
  }
  
  
  if((A-1)<=(N-B)){
    ans = A;
  	ans += abs(B-A-1)/2;
  
  	cout << ans << endl;
    return 0;
  }
  else{
    ans = N-B+1;
    ans += abs(B-A-1)/2;
    
    cout << ans << endl;
    return 0;
  }
  
  return 0;
}