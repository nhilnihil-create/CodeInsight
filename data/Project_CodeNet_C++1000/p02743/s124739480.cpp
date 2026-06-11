#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x>y?x:y;return;} 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

ll a,b,c;

int main()
{
	cin>>a>>b>>c;
	if(c-a-b<0) cout<<"No"<<endl;
	else if((c-a-b)*(c-a-b)>4*a*b) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}