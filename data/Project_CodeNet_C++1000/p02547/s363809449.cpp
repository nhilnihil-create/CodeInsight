#include <bits/stdc++.h>
 
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sll set<long long>
#define si set<int>
#define sti stack<int>
#define stkl stack<ll>
#define qi queue<int>
#define pb push_back
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mod=1e9+7;
using namespace std;
int c=0;

void solve(){
	int n;
	cin>>n;

	vector<pii> a(n);

	for(int i=0;i<n;i++){
		cin>>a[i].ff>>a[i].ss;
	}

	for(int i=0;i<n-2;i++){
		int c=0;
		for(int j=0;j<3;j++){
			if(a[i+j].ff!=a[i+j].ss)
				break;
			else
				c++;
		}

		if(c==3){
			cout<<"Yes"<<endl;
			return;
		}
	}

	cout<<"No"<<endl;
}
 
int main(){
    IOS;
    int q=1;
    //cin>>q;
    while(q--){
    	c++;
        solve();
    }
}
