#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=50;

int n,a[N+9];
string s[N+9],t;

void into(){
  cin>>n;
  for (int i=1;i<=n;++i)
	cin>>s[i]>>a[i];
  cin>>t;
}

int ans;

void Get_ans(){
  int flag=0;
  for (int i=1;i<=n;++i){
	ans+=flag*a[i];
	if (s[i]==t) flag=1;
  }
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}