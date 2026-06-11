/******************************************
* AUTHOR : GURUTEJA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100005
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

void debug(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

}

  int main() {
    debug();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a,b,m,p,q,c,sum=0,minno=1e18,maxno=1e18;
    cin>>a>>b>>m;

    long long int x[a],y[b];

    for (int i = 0; i <a; ++i)
    {
    	cin>>x[i];
    	minno=min(minno,x[i]);
    }

    for (int i = 0; i <b; ++i)	
    {
    	cin>>y[i];
    	maxno=min(maxno,y[i]);
    }
    sum=(minno+maxno);
    for (int i = 0; i <m; ++i)
    {
    	cin>>p>>q>>c;
    	sum=min(sum,((x[p-1]+y[q-1])-c));
    }
     

    cout<<sum<<endl;

    return 0;
  }