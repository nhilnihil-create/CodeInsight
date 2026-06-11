#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#include<iostream>
#define MAX 1000
#define TS 13
#define rep(i,a) for(i=1;i<=a;i++)
using namespace std;
typedef pair<char,int> p;
int main(void)
{
	int n,i,j;
	p card[53];
	int s[TS+1],h[TS+1],c[TS+1],d[TS+1];
	rep(i,TS) {
		s[i]=MAX;
		h[i]=MAX;
		c[i]=MAX;
		d[i]=MAX;
	}
	cin>>n;
	rep(i,n) cin>>card[i].first>>card[i].second;
	rep(i,n) {
		if(card[i].first=='S') s[card[i].second]=card[i].second;
		else if(card[i].first=='H') h[card[i].second]=card[i].second;
		else if(card[i].first=='C') c[card[i].second]=card[i].second;
		else d[card[i].second]=card[i].second;
	}
	rep(i,TS) if(s[i]==MAX) cout<<"S "<<i<<endl;
	rep(i,TS) if(h[i]==MAX) cout<<"H "<<i<<endl;
    rep(i,TS) if(c[i]==MAX) cout<<"C "<<i<<endl;
	rep(i,TS) if(d[i]==MAX) cout<<"D "<<i<<endl;
	return 0;
}