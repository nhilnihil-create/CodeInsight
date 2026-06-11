#include<bits/stdc++.h>
using namespace std;
#define very_slow       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define inf             1e18
#define MAX             1e9
#define MIN            -1e9
#define no_of_test(x)        int x; cin>>x; while(x--)
//Actual Code Is At The Top
const int mod = 1e9 + 7;
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int binary_exponentation(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}
int32_t main()
{   
	very_slow
//	no_of_test(x)
	{  
         int a[3][3];
		 for(int i=0;i<3;i++)
		 {
             for(int j=0;j<3;j++)
			 {
				 cin>>a[i][j];
			 }
		 }
		 int q;
		 cin>>q;
		 while(q--)
		 {
			 int n;
			 cin>>n;
			 for(int i=0;i<3;i++)
		    {
             for(int j=0;j<3;j++)
			 {
				 if(a[i][j]==n)
				 {
					 a[i][j]=1;
					 break;
				 }
		 	 }
	       }
		 }
		 string s="No";
		 for(int i=0;i<3;i++)
		 {
			 if(a[i][0]==1 && a[i][1]==1 && a[i][2]==1)
			 {
				 s="Yes";
				// break;
				 //continue;
			 }
		 }
		 for(int i=0;i<3;i++)
		 {
			 if(a[0][i]==1 && a[1][i]==1 && a[2][i]==1)
			 {
				s="Yes";
				// break;
				 //continue;
			 }
		 }
         if(a[0][0]==1&&a[1][1]==1&&a[2][2]==1) s="Yes";
		 if(a[2][0]==1&&a[1][1]==1&&a[0][2]==1) s="Yes";
		 cout<<s<<'\n';
		 
	}
	return 0;
}