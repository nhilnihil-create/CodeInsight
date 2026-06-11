#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define ld long double
#define d1(x)  cerr << #x << "--> " << x << endl
#define d2(x, y)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<endl
#define d3(x, y,z)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<" | " << #z << "--> "<< z<< endl
#define vpll vector<pair<ll,ll>>
#define F first
#define S second
using namespace std;

ll mode=pow(10,9)+7;
bool cmp(pair<ll,ll> x, pair<ll, ll> y){
	return x.S<y.S;
}


int main(){ 
    
    #ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
	#endif
	
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	
	ll n;
	cin>>n;
	if (n%2==0){
		n=n/2;
		cout<<n-1<<endl;
	}
	else{
		n=n/2;
		cout<<n<<endl;
	}
	
	
 	return 0;
}