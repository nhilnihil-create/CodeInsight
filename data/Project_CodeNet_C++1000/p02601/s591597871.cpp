#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define ull unsigned ll
#define uint unsigned
#define pai pair<int,int>
#define pal pair<ll,ll>
#define IT iterator
#define pb push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);--i)
#define endl '\n'
#define ll long long
int main()
{
    int x,y,z;
    cin>>x>>y>>z;
 	int timess ;
  	cin >> timess;
  	if(y ==0 || z== 0){
    	cout<<"No"<<endl;
      return 0;
    }
  	int time1 = 0 ;
  	int time2 = 0;
  	while(y<= x){
    	y = y*2;
          time1++;
    }
  while(z <= y){
    z=z*2;
    time2++;
  	}
  if(time1 + time2 <= timess){
  	cout<<"Yes"<<endl;
    return 0;
  }else {
  cout<<"No"<<endl;
    return 0;
  }
}
