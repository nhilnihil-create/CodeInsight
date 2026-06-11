#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define whln(t) while(t--)
#define whlp(t) while(t++)
ll i=0,j=0;


int main(void){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	 // int t ;
	 // cin>>t;
	 // whln(t){

   	ll arr[3][3];
   	rep(i,3)
   		rep(j,3)
   			cin>>arr[i][j];
   	ll  n ;
   	cin>>n;
   	set<ll> b;
   	rep(i,n){
   		ll x ;
   		cin>>x;
   		b.insert(x);
   	}

   	rep(i,3)
   		rep(j,3){
   			if(b.find(arr[i][j])!=b.end())
   				arr[i][j]=0;
   		}
   	bool f = false;	
   	rep(i,3){
   		if(arr[i][0]==0 && arr[i][1]==0 && arr[i][2]==0)
   			f = true ;
   	}
   	rep(i,3){
   		if(arr[0][i]==0 && arr[1][i]==0 && arr[2][i]==0)
   			f = true ;
   	}

   	if(arr[0][0]==0&&arr[2][2]==0&&arr[1][1]==0)
   		f = true ;
   	if(arr[0][2]==0 && arr[1][1]==0 && arr[2][0]==0)
   		f = true ;

   	if(f)
   		cout<<"Yes";
   	else
   		cout<<"No";
   			
   		

}
//   *****  *******   !
//   *		     *    !
//   ***       *      !
//   *       *        !
//   *****  *******   !