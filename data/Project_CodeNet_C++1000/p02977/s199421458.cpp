#include<bits/stdc++.h>
using namespace std;
#define int long long int
// #define lli llong int 
#define ld long double
#define ff first
#define ss second
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define f(i,j,l) for(i=j;i<l;i++)
#define scan(n) scanf("%lld",&n)
#define endl "\n"
ld const pi = 3.141592653589793238462;

int const mod = 1e9+7;
int const mod1 = 1e9+6;

int power(int a,int b){
    	int f=1;
    	while(b>0){
		if(b&1){
			f=f*a;
			f%=mod;
		}
		a=a*a;
		a%=mod;
		b=b/2;
	}
	return f;
}

int inverse_mod(int x){
    	return power(x,mod-2);
}

int const N = 1e5+5;
vector<int> adj[N];


int32_t main(){
	IOS;
	int n,i,j,l;
	cin>>n;
	if(n < 3){
		cout<<"No"<<endl;
		return 0;
	}
	int is = 1;
	i = 1;
	while((1<<i) <= n){
		if(n == (1<<i)){
			is = 0;
		}
		i++;
	}
	if(is == 0){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	
	for(i=1;i<3;i++){
		cout<<i<<" "<<i+1<<endl;
	}
	cout<<"3 "<<n+1<<endl;
	cout<<n+1<<" "<<n+2<<endl;
	cout<<n+2<<" "<<n+3<<endl;
	if(n%2 == 0){
		for(i=4;i<n;i+=2){
			cout<<i<<" 1"<<endl;
			cout<<"1 "<<n+i+1<<endl;
			cout<<n+i+1<<" "<<n+i<<endl;
			cout<<i<<" "<<i+1<<endl;
		}
		for(i=0;;i++){
			if(n&(1<<i)){
				j = n^(1<<i);
				l = (1<<i);
				cout<<n<<" "<<l<<endl;
				cout<<2*n<<" "<<n+j+1<<endl;
				break;
			}
		}
	}
	else{
		for(i=4;i<=n;i+=2){
			cout<<i<<" 1"<<endl;
			cout<<"1 "<<n+i+1<<endl;
			cout<<n+i+1<<" "<<n+i<<endl;
			cout<<i<<" "<<i+1<<endl;
		}
	}
 	return 0;
}

/*

1 0 1 0 1




*/