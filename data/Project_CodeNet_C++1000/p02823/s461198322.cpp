#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

bool compare(vector<ll> a, vector<ll> b){
	if(a[0]<b[0]) return true;
	if(a[0]==b[0]){
		if(a[1]<b[1]) return true;
		return false;
	}
	return false;
}

void solve(){
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	//for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
	//for getting output from output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	ll n,a,b,i,j,count=0,temp;
	cin>>n>>a>>b;
	temp = max(a,b);
	a = min(a,b); b = temp;
	if((b-a)%2==0){ cout<<(b-a)/2; return 0; }
	cout<<min(n-b+1,a)+(b-a)/2;


}