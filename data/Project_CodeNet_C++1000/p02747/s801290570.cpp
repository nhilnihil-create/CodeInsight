#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=a;i--)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define de(x) cout << #x << "=" << x << endl
#define dd(x) cout << #x << "=" << x << " "
#define pw(x) (1ll<<(x))
#define pq priority_queue
#define endl "\n"
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if(s.size()%2!=0){
    	cout <<"No";
    	return 0;
	} 
	for(int i=0;i<s.size();i++){
		if(i%2==0 && s[i]!='h'){
			cout <<"No";
			return 0;
		}
		if(i%2==1 && s[i]!='i'){
			cout <<"No";
			return 0;
		}
	}   
	cout <<"Yes";
    return 0;
}
