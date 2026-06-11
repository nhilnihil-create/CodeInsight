#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int ans=0,n=s.length();
    for(int i=0;i<n/2;i++)
    {
    	if(s[i]!=s[n-i-1])
    	{
    		ans++;
    	}
    }
    cout<<ans<<endl;
}