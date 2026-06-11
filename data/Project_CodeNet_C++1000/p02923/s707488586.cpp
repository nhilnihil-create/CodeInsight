#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

const int maxm = 1000000000 + 7;


using namespace std;


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;

	ll a[n];

	loop(i,n)
	{
		cin>>a[i];
	}

	int ans=0;
	int max_ans=0;

   loop(i,n)
   {
   	  if(a[i+1] <= a[i])
   	  {
   	  	 ans++;
   	  }

   	  else
   	  {
   	  	if(max_ans < ans)
   	  	{
   	  		max_ans = ans;
   	  		
   	  	}

   	  	ans=0;
   	  }
   }

   if(max_ans < ans)
   {
   	  max_ans = ans;
   }

  cout<<max_ans<<endl;





}