#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define fi first
#define se second
#define merge(a,b) a##b //concat a and b
#define mkstr(a) #a  //convert a to string a. a is not variable
#define flush fflush(stdout);
#define debug(x) cout<<#x<<endl;
#define debug1(x) cout<<x<<endl;
#define inf 1e18
#define endl "\n"
#define epsilon 1e-9

typedef long long int ll;
typedef long double   ld;
typedef unsigned long long int ull;

/************************************TEMPLATE**********************************/

ll modpower(ll x,ll y)
{
  ll res=1;
  x=x%mod;
  if(x==0) return 0;
  while(y>0)
  {
    if(y&1)
      res=(res*x)%mod;
    y=y>>1;
    x=(x*x)%mod;
  }
  return res;
}

/*************************************CODE*************************************/



int main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  fastIO
  ll test_case=1;
  //cin>>test_case;
  while(test_case--)  {
    int h,w,m;
    cin>>h>>w>>m;
    int row_count[h],column_count[w];
    set<pair<int,int>> target;
    memset(row_count,0,sizeof(row_count));
    memset(column_count,0,sizeof(column_count));
    int x,y,max_row=0,max_column=0;
    for(int i=0;i<m;i++)	{
    	cin>>x>>y;
    	x--,y--;
    	target.insert(mp(x,y));
    	row_count[x]++;
    	max_row=max(max_row,row_count[x]);
    	column_count[y]++;
    	max_column=max(max_column,column_count[y]);
    }
    vector<int> row_idx,column_idx;
    //cout<<max_row<<" "<<max_column<<endl;
    for(int i=0;i<h;i++)	{
    	//cout<<row_count[i]<<" ";
    	if(row_count[i]==max_row)
    		row_idx.pb(i);
    }
    //cout<<endl;
    for(int i=0;i<w;i++)	{
    	//cout<<column_count[i]<<" ";
    	if(column_count[i]==max_column)
    		column_idx.pb(i);
    }
    //cout<<endl;
    int ans=0;
    for(int i:row_idx)	{
    	for(int j:column_idx)	{
    		//cout<<"("<<i<<","<<j<<")"<<endl;
			ans=max(ans,row_count[i]+column_count[j]-1);
    		if(target.count(mp(i,j))==0)	{
    			ans++;
    			goto out;
    		}
    	}
    }
    out:
    cout<<ans<<endl;
  }
  return 0;
}
