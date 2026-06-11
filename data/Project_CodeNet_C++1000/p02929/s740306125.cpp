#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000
#define ALL(v) (v).begin(), (v).end()
const int mod = INF+7;
using namespace std;

int factorial(int n){
  int pro=1;
  srep(i,1,n+1){
    pro=(long)pro*i%mod;
  }
  return pro;
}

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  int *lr=(int *)malloc(sizeof(int)*N*2);
  //left:0, right:1
  if(S[0]=='W' || S[2*N-1]=='W'){
    printf("%d\n", 0);
  }
  else{
    lr[0]=0;
    srep(i,1,N*2){
      if(S[i-1]==S[i]){
        if(lr[i-1]==0){
          lr[i]=1;
        }
        else{
          lr[i]=0;
        }
      }
      else{
        if(lr[i-1]==0){
          lr[i]=0;
        }
        else{
          lr[i]=1;
        }
      }
    }
    int count=0;
    int sum=1;
    rrep(i,N*2){
      if(lr[i]==1){
        count++;
      }
      else if(lr[i]==0){
        sum=(long)sum*count%mod;
        count--;
      }
    }
    if(count!=0){
      printf("%d\n", 0);
    }
    else{
      sum=(long)sum*factorial(N)%mod;
      printf("%d\n", sum);
    }
  }


}
