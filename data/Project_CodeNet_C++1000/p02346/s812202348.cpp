#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  ll n,q;
  cin >> n >> q;

  int a[n+5]={0};
  int com[q],x[q],y[q];
  REP(i,q){

    //cin >> com[i] >> x[i] >> y[i];
    scanf("%d %d %d",&com[i],&x[i],&y[i]);

  }
  REP(i,q){
    if(com[i] == 0){
      a[x[i]] += y[i];
    }
    else{
      ll c = 0;
      for(int j = x[i];j < y[i]+1;j++){
	c += a[j];
      }
      printf("%d\n",c);
    }
  }
  
}