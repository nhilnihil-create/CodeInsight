#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;

  cin>>n;

  for(int i=0;i<n;++i){
    int y,m,d;
    int cnt=0;

    cin>>y>>m>>d;

    if(d!=1){
      if(y%3==0 || m%2!=0)
	cnt=20-d+1;
      else
	cnt=19-d+1;
      m++;
      if(m==11){
	m=1;
	y++;
      }
    }

    if(m!=1){
      if(y%3==0)
	cnt=cnt+(10-m+1)*20;
      else
	while(m!=11){
	  if(m%2==0)
	    cnt+=19;
	  else
	    cnt+=20;
	  m++;
	}
      y++;
    }

    while(y!=1000){
      if(y%3==0)
	cnt+=20*10;
      else
	cnt=cnt+20*5+19*5;
      y++;
    }
    cout<<cnt<<endl;
  }
}