#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define pb push_back

int main() {
  int a,b,c;
  
  while(true){
    cin>>a>>b>>c;
    if(a==0&&b==0&&c==0)break;
    int  ans=0;
    for(int i=1;i<c;i++){
      int x=i;
      int y=c-i;

      int bx=-1, by=-1;
      rep(j,x+1)
	{
	  int t = j*(100+a)/100;
	  if(t==x)
	    {
	      bx = j;
	    }
	  
	}
      rep(j,y+1)
	{
	  int t = j*(100+a)/100;
	  
	  //if(y==994)printf("%d %d\n",(int)t, j);
	  if(t==y)by = j;
	}
      if(bx==-1||by==-1)continue;
      
      
      
      int t1=bx*(100+b)/100;
      int t2=by*(100+b)/100;

      // printf("%d %d %d %d %d %d\n",x,y,(int)bx,(int)by,(int)t1,(int)t2);
      
      if(t1+t2>ans){
	ans=t1+t2;
      }
    }

      cout<<ans<<endl;
      
      
    
  }
}