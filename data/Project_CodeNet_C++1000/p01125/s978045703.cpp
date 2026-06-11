#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<cmath>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define int long long  
using namespace std;
const int INF=1000000007;
signed main(){
  int n;
  while(cin>>n,n!=0){
    int mp[21][21]={};
    rep(i,n){
      int x,y;
      cin>>x>>y;
      mp[y][x]=7;
    }
    int m;
    cin>>m;
    int nx=10,ny=10;
    int sum=0;
    rep(i,m){
      char a;
      int b;
      cin>>a>>b;
      if(a=='N'){
	rep(i,b){
	  if(mp[ny+i+1][nx]==7){
	    sum++;
	    mp[ny+i+1][nx]=0;
	  }
	}
	ny+=b;
      }else if(a=='E'){
	rep(i,b){
	  if(mp[ny][nx+i+1]==7){
	    sum++;
	    mp[ny][nx+i+1]=0;
	  }
	}
	nx+=b;
      }else if(a=='S'){
	rep(i,b){
	  if(mp[ny-i-1][nx]==7){
	    sum++;
	    mp[ny-i-1][nx]=0;
	  }
	}
	ny-=b;
      }else if(a=='W'){
	rep(i,b){
	  if(mp[ny][nx-i-1]==7){
	    sum++;
	    mp[ny][nx-i-1]=0;
	  }
	}
	nx-=b;
      }
    }
    cout<<((sum==n)?"Yes":"No")<<endl;
  }
  return 0;
}