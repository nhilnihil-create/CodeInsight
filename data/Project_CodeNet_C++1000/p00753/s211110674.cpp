#include<iostream>
using namespace std;
int prime[1000000];
bool is_prime[1000001];

int sieve(int n){
  int p=0;
  for(int i=0;i<=n;i++)is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;
  for(int i=0;i<=n;i++){
    if(is_prime[i]==true){
      prime[p++]=i;
      for(int j=2*i;j<=n;j+=i)is_prime[j]=false;
    }
  }
  return p;
}



int main(){
  int n;
  while(cin>>n,n)
    cout<<sieve(2*n)-sieve(n)<<endl;
  return 0;
}