#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

priority_queue<int> bo;
priority_queue<int, vector<int>, greater<int> > so;
int cheak[100];

int num(char s){
  int r;
  if(s=='1')r=1;
  else if(s=='2')r=2;
  else if(s=='3')r=3;
  else if(s=='4')r=4;
  else if(s=='5')r=5;
  else if(s=='6')r=6;
  else if(s=='7')r=7;
  else if(s=='8')r=8;
  else if(s=='9')r=9;
  else if(s=='0')r=0;
  return r;
}

main(){
  char s[6];
  int n;
  int match;
  int ma,mb;
  int t,c;
  while(cin >> s >> n,s=="0"|| n){
    match=0;
    cheak[0]=0;
    
    for(int i=0;i<strlen(s);i++){
      cheak[0]*=10;
      cheak[0]+=num(s[i]);
    }

    t=cheak[0];
    for(int i=1;i<=20 && match==0;i++){
      for(int j=0;j<n;j++){
	c=t%10;
	bo.push(c);
	so.push(c);
	t=t/10;
      }
      for(int j=0;j<n;j++){
	t=t*10;
	t+=bo.top()-so.top();
	bo.pop();so.pop();
      }
      for(int j=0;j<i;j++){
	if(cheak[j]==t){
	  ma=i;
	  mb=j;
	  match=1;
	}
      }
      cheak[i]=t;
    }
    cout << mb << " " << cheak[mb] << " " << ma-mb << endl;
  }
}