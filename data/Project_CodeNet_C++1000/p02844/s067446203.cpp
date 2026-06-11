#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define All(a) (a).begin(),(a).end()

int main(){ 
  ll n,cnt=0;
  string s;
  int tmp;
  ll ans[1000]={};
  cin>>n>>s;
  ll S[n][10]={};
  for(int i=0;i<n;i++){
    tmp=s[i]-'0';
    for (int j = i; j<n; j++){
      S[j][tmp]++;
    }
  }

  for(int i=1; i < s.size()-1;i++){
    tmp=s[i]-'0';
    for(int j=0;j<10;j++){
      if(S[i-1][j]){
        for(int k=0;k<10;k++){
          if(S[n-1][k]-S[i][k]){
            ans[tmp*100+10*j+k]++;
          }
        }
      }
    }
  }
  for (int i = 0; i <1000; i++)
  {
    if (ans[i]>0)cnt++;
  }


  cout << cnt <<endl;
  return 0;
}