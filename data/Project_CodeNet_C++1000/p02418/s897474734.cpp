#include<iostream>
#include<string.h>
using namespace std;

int judge();
char s[202],p[101];
int y;
int main()
{
  cin>>s;
  cin>>p;
  y=strlen(s);
  for(int i=0;i<y;i++){
    s[y+i]=s[i];
  }
  if(judge())cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}

int judge(){
  int sum=0;
  for(int i=0;i<y;i++){
    for(int j=0;j<strlen(p);j++){
      if(s[i+j]==p[j])sum++;
    }
    if(sum==strlen(p))return 1;
    else sum=0;
  }
  return 0;
}