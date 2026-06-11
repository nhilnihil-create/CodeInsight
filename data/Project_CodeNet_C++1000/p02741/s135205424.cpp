#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define inf 1000000000
#define mod 1000000007
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;

int k;
int a[]={0 ,1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main()
{
	cin>>k;
	cout<<a[k]<<endl;
	return 0;
}