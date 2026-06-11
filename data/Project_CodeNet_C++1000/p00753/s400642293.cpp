#include<bits/stdc++.h>
using namespace std;
#define lint long long int
#define REP(i,n) for(lint i = 0; i < n ;i++)
const int N= 123456*2+100;
bool isprime[N];

int main()
{
  lint n;
  lint a = 0;
 for(lint a = 2;a<N;a++){
    for(lint i = a*2;i < N;i+=a){
      isprime[i] = true;
    }
 }
  while(cin>>n,n){
    lint ans=0;
    for(lint i = n+1;i < 2*n+1;++i){
      if(!isprime[i])ans++;
    }
    cout << ans << endl;

  }
  

  
}