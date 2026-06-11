#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
//#define in(i,n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define graph vector< vector<int> >
#define vs vector<string>
#define mn -
#define pls +
#define mod %
#define E =
#define EE ==
#define le <=
#define ge >=
int mx=9999999;
/**  '' "\n" - ^ **/

    void yes()
    {
        cout<<"yes\n";
    }

    void no()
    {
        cout<<"no\n";
    }
    void YES()
    {
        cout<<"YES\n";
    }

    void NO()
    {
        cout<<"NO\n";
    }

    void Case(int i,int n)
    {
        cout<<"Case:"<<i<<" "<<n<<endl;
    }
    /**  '' "\n" x ^ **/
    /** printf("\n") */
inline int inc(int i,int j)
{
	return i + j;
}
inline int dec(int i,int j)
{
	return i - j;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    int mx E 0;
    for(int i E 0;i le a.length() mn b.length();i E i pls 1)
    {
    	int c E 0;
    	for(int j E 0,k E i;j<b.length();j E inc(j,1),k E inc(k,1))
    	{
    		if(b[j] EE a[k])c E inc(c,1);
		}
		if(c > mx)
		mx E c;
	}
	pf(b.length() mn mx);
}
