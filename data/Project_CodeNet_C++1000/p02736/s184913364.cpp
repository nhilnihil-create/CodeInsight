#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1e9+7;
//const ll MOD=998244353;

int cnt[3];
int num2[1010101];

void prepare(){
  for(int i=1;i<=1010100;i++){
    int tmp=0,x=i;
    while(x%2==0) x/=2,tmp++;
    num2[i]=num2[i-1]+tmp;
  }
}

int main(){
  prepare();
  
  int N; cin>>N;
  string S; cin>>S;
  int A[N];
  rep(i,N){
    A[i]=(S[i]-'0');
    A[i]--;
    cnt[A[i]]++;
  }
  
  if(cnt[1]){
    int ans=0;
    rep(i,N){
      if(A[i]%2){
        int x=num2[N-1]-num2[N-1-i]-num2[i];
        if(x==0) ans++;
      }
    }
    if(ans%2) cout<<"1\n";
    else cout<<"0\n";
  }else{
    int ans=0;
    rep(i,N){
      if(A[i]==2){
        int x=num2[N-1]-num2[N-1-i]-num2[i];
        if(x==0) ans++;
      }
    }
    if(ans%2) cout<<"2\n";
    else cout<<"0\n";
  }
  return 0;
}