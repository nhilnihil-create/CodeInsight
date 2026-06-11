#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char c[110];
int main(){

  int a,b;
  cin >> a >> b;
  for(int i=0;i<b;i++)c[i]='0'+a;
  string s=c;
  for(int i=0;i<a;i++)c[i]='0'+b;
  c[a]=0;
  string s1=c;
  printf("%s\n",min(s,s1).c_str());
}