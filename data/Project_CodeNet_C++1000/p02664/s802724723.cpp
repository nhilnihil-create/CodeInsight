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
  
  	string s;
  	cin>>s;
  	REP(i,0,s.size())
  	{
  		if(s[i] == '?')
  		s[i] = 'D';
	}
     cout<<s<<"\n";

   return 0;
}
