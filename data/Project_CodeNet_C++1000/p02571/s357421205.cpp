#include<bits/stdc++.h>
#define lli long long int
#define ulli unsigned long long int
#define ld long double
#define loop(i,m,n) for(lli i=m;i<=n;i++)
#define loopr(i,m,n) for(lli i=m;i>=n;i--)
#define pb push_back
#define vi vector<int>
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1000000000
#define mod 1000000007
#define siz 1000001
#define endl "\n"
const double PI=3.14159265358979323846264338327950288419716939937510;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

int main()
{
	int i,j,n,m,ans=INT_MAX;
	string s,t;
	cin>>s>>t;
	n=s.size();
	m=t.size();
	for (i = 0; i <= n - m; i++)
    {
        int needchange = 0;
        for (j = 0; j < t.length(); j++)
        {
            if (s[i+j] != t[j])
            {
                needchange++;
            }
        }
            ans = min(ans, needchange);
    }
    cout<<ans<<endl;
    return 0;
}
/*
cabacc
abc

codeforces
atcoder
*/
