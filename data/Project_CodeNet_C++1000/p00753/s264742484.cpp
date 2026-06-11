#include<bits/stdc++.h>
using namespace std;
const int MAX_N=300000;
bool isPrime[MAX_N];
void eratos(){
  for(int i=0;i<MAX_N;i++)isPrime[i]=true;
  isPrime[0]=isPrime[1]=false;
  for(int i=0;i<MAX_N;i++){
    if(isPrime[i]){
      for(int j=i+i;j<MAX_N;j+=i){
        isPrime[j]=false;
      }
    }
  }
}
int main()
{
  eratos();
  while(true)
  {
    int n;
    cin>>n;
    if(n==0)
    {
      break;
    }
    int count=0;
    int s=n+1;
    int e=2*n;
    for(int i=s;i<=e;i++)
    {
      if(isPrime[i])
      {
        count++;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}

