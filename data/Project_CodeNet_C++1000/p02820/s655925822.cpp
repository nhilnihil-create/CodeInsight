#include <bits/stdc++.h>
using namespace std;

#define	rep(i,n)	for(int i=0;i<n;i++)

int n,k,r,s,p;

char check(char c){
  if(c=='r')	return 'p';
  if(c=='s')	return 'r';
  if(c=='p')	return 's';
}

int score(char c){
  if(c=='r')	return r;
  if(c=='s')	return s;
  if(c=='p')	return p;
}

int main() {
  cin >> n >> k >> r >> s >> p;
  vector<char> kyoutai(n);
  rep(i,n)	cin >> kyoutai[i];
  
  int ans=0;
  
  vector<char>	jibun(n,'x');
  for(int i=0;i<k;i++){
    jibun[i]=check(kyoutai[i]);
    ans+=score(jibun[i]);
  }
   
  for(int i=k;i<n;i++){
    if(check(kyoutai[i])==jibun[i-k])	continue;
    jibun[i]=check(kyoutai[i]);
    ans+=score(jibun[i]);
  }
  cout << ans;
}
