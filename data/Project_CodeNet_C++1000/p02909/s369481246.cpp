// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

string ss[]={"Sunny","Cloudy","Rainy"};


int main(){	
	string s;cin>>s;
	int id=-1;
	For(i,0,3){
		if(s==ss[i])id=i;
	}
	id=(id+1)%3;
	cout<<ss[id]<<endl;

	return 0;
}
