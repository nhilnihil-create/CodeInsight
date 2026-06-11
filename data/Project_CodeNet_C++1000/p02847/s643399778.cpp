#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define ll long long int 
#define PI 3.1415926535897932384626

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	string arr[]={"SUN", "MON", "TUE", "WED", "THU", "FRI","SAT"};
	int index=0;
	for(int i=0;i<7;i++)
	{
	     if(s==arr[i]){
	     index=i;
	     break;
	     }
	}
	cout<<7-index;
	return 0;
}