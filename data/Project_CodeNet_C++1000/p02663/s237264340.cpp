//Author : Prakhar Asaiya
#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(ll i=a;i<b;++i)
#define REPN(i,a,b) for(ll i=a;i<=b;++i)
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define ll long long
#define ld long double
const int M=1e9+7;



int main()
{/*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#*/
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  	int h1,m1,h2,m2,k;
  	cin>>h1>>m1>>h2>>m2>>k;
  	int t1 = h1*60 + m1;
  	int t2 = h2*60 + m2;
  	int diff = t2-t1;
  	cout<<diff-k<<"\n";
  	


   return 0;
}
