
#include <iostream>
#include <string>
using namespace std;
 
#define endl "\n"
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define mem(a,b) memset((a),(b),sizeof (a))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF long long(1e18)
#define MOD 1000000007


void solve(){
	string s;
	cin>>s;
	if(s[2]==s[3]&&s[4]==s[5]) 
	cout<<"Yes"<<endl; 
	else cout<<"No"<<endl;  
}

int32_t main(){
    int t=1;
    while(t--)
        solve();
    return 0;
}


