#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
  int h;
  while(cin>>h,h){
    int num[h][5]={};
    for(int i=0;i<h;i++)
      for(int j=0;j<5;j++)
	cin>>num[i][j];
    int ans=0;
    while(1){
      bool flag=true;
      vector<pair<pair<int,int>,int> >kesi;
      for(int i=0;i<h;i++){
	int cnt=1;
	pair<int,int> doko=mp(INF,0);
	for(int j=0;j<4;j++){
	  if(num[i][j]!=0&&num[i][j]==num[i][j+1]){
	    if(doko.S==0)
	      doko=mp(min(doko.F,j),num[i][j]);
	    
	      cnt++;
	  }else{
	    if(cnt>=3){
	      flag=false;
	      kesi.pb(mp(mp(doko.F,doko.F+cnt-1),i));
	      ans+=cnt*doko.S;
	      //   cout<<ans<<endl;
	    }
	    doko=mp(INF,0);
	    cnt=1;
	  }
	}
	if(cnt>=3){
	  flag=false;
	  kesi.pb(mp(mp(doko.F,doko.F+cnt-1),i));
	  ans+=cnt*doko.S;
	  // cout<<cnt<<" "<<doko.S<<" "<<ans<<endl;
	}
      }
      if(flag)break;
      for(int i=kesi.size()-1;i>=0;i--){
	  for(int k=kesi[i].F.F;k<=kesi[i].F.S;k++){
	    num[kesi[i].S][k]=0;
	  }
	}
      

      for(int i=h-1;i>=0;i--){
	for(int j=0;j<5;j++){
	  int hei=i;
	  while(num[hei][j]==0&&hei>0){
	    hei--;
	  }
	  if(num[i][j]==0){
	  num[i][j]=num[hei][j];
	  num[hei][j]=0;
	  }
	}
      }
  
    }
    cout<<ans<<endl;
  }
  return 0;
}

