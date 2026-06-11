#include<iostream>
using namespace std;

int main(){
  long long K;
  cin >> K;
  
  long long n=7;
  long long m=n;
  long long ans=1;
  
  if(K%2==0 || K%5==0){
    ans=-1;
  }
  else{
    for(int i=0; i<K; i++){
      if(m%K==0){
        break;
      }
      n = n*10%K;
      m=(m+n)%K;
      ans++;
    }
  }
  
  cout << ans << endl;
      
  
  return 0;
}