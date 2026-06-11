#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

ll x;
int main(){
	// debug;
	ios;

	cin>>x;
	ll sum = 100;
	ll cnt = 0;
	while(sum<x){
		sum += sum/100;
		cnt++;
	}
	cout<<cnt<<'\n';
	

	return 0;
}
