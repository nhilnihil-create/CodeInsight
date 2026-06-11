#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll N,M,i;
  ll p[222222];
  ll WA[222222]; //WAの回数
  ll AC[222222]; //ACしてたら1,してなかったら0
  string S[222222];
  cin >> N >> M;
  for(i=0;i<=M-1;i++){
    cin >> p[i] >> S[i];
    if(S[i]=="AC" && AC[p[i]]==0) AC[p[i]]=1;
    if(S[i]=="WA" && AC[p[i]]==0) WA[p[i]]++;
  }
  ll A = 0;
  ll W = 0;
  for(i=1;i<=N;i++){
    A += AC[i];
    if(AC[i]==1) W += WA[i];
    }
  cout << A << " " << W << endl;
} 