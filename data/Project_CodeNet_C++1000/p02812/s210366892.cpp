#include <bits/stdc++.h>
using namespace std;
typedef  long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define int long long int
#define F first
#define S second
#define pb push_back
#define check(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define INF 1e9+5
#define N 200005



signed main()
{

		int n,ans=0;
		cin>>n;
		string s,f="ABC";
        cin>>s;
       	for(int x=0;x<n;x++){
        	string k=s.substr(x,3);
            if(k==f){ans++;}
        }
    	    cout<<ans<<endl;

}
