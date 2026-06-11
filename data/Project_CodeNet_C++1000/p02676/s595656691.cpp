#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
using namespace std;
template <typename T> T Max(T X,T Y){return X>Y?X:Y;}
template <typename T> T Min(T X,T Y){return X<Y?X:Y;}
template <typename T> void chmax(T &X,T Y){X=X>Y?X:Y;return;}
template <typename T> void chmin(T &X,T Y){X=X<Y?X:Y;return;}

int k;
string s;

int main()
{
	cin>>k;
	cin>>s;
	if(sz(s)<=k) cout<<s<<endl;
	else
	{
		for(int i=0;i<k;i++)
			cout<<s[i];
		cout<<"..."<<endl;
	}
	return 0;
}