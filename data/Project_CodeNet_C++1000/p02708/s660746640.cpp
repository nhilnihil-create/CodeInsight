#include<iostream>
const unsigned int M= 1000000007;
using namespace std;

int main()
{
 long long int n,k;
  cin>>n>>k;
  long long int ans=0;
 
  long long int sm[200005]={0};
  for(int i=1;i<200005;i++)sm[i]=sm[i-1]+i;
  for(int i=k;i<=(n);i++)
  {
    long long int mini=sm[i-1];
    long long int maxi=sm[n]-sm[n-i];
    
    ans+=(maxi-mini+1);
    
    ans%=M;
    
  }
          cout<<(ans+1)%M<<endl;
  
}