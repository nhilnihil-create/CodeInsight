#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define rep(a,b,c) for(int a=1;a<=b;a+=c)
#define repp(a,b,c,d) for(int a=b;a<=c;a+=d)

const double PI=acos(-1);
const double EPS=1e-12;
const int MOD=1e9+7;
const int INF=1<<30;


using namespace std;


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int a,b,c,d;
	cin>>a>>b;
	cin>>c>>d;
	if(a==1||a==3||a==5||a==7||a==8||a==10||a==12){
		if(b==31)cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(a==2){
		if(b==28)cout<<1<<endl;
		else cout<<0<<endl;
	}
	else{
		if(b==30)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
