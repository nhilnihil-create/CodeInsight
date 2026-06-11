#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
#include<cmath>
#define mod 1000000007
#define inf 1000000000000000
#define int long long int
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int n;
     cin>>n;
     int arr[n+1];
     int j;
     for(j=1;j<=n;j++)
     {
		 cin>>arr[j];
	 }
	 int value[n+1]={0};
	 for(j=n;j>=1;j--)
	 {
		 int sum=0;
		 for(int i=2;i*j<=n;i++)
		 {
			 sum+=value[i*j];
			 sum%=2;
		 }
		 if(sum==arr[j])
		    value[j]=0;
		 else
		   value[j]=1;
	 }
	 vector<int> vec;
	 for(j=1;j<=n;j++)
     {
		 if(value[j])
		 {
			 vec.push_back(j);
		 }
	 }
	 cout<<vec.size()<<endl;
	 for(int x:vec)
	   cout<<x<<" ";
	 cout<<endl;
}
