#include<bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

string s;

int main()
{
	cin>>s;
	if(s[2]==s[3]&&s[4]==s[5]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}