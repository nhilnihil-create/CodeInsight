#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1) * a % MOD;
	}
}

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

int main(void){
	int n;
	cin>>n;
	if(n<=2){
		cout<<"No"<<endl;
		return 0;
	}else if(n==3){
		cout<<"Yes"<<endl;
		reps(i,n*2-1){
			cout<<i<<" "<<i+1<<endl;
		}
		return 0;
	}

	int memo = n;

	while(true){
		if(memo%2==1){
			break;
		}
		memo /= 2;
		if(memo == 1){
			cout<<"No"<<endl;
			return 0;
		}
	}

	cout<<"Yes"<<endl;
	reps(i,2){
		cout<<i<<" "<<i+1<<endl;
		cout<<i+n<<" "<<i+1+n<<endl;
	}
	cout<<1<<" "<<n+3<<endl;

	ll keta = 2;
	reps(i,n){
		if(i<=3) continue;
		if(i == keta*2){
			keta*=2;
		}
		if(i == n){
			cout<<i<<" "<<keta+1<<endl;
			if(i-keta == 2){
				cout<<i-keta<<" "<<i+n<<endl;
			}else{
				cout<<i-keta+n<<" "<<i+n<<endl;
			}
			
			break;
		}



		cout<<i<<" "<<i+1<<endl;
		cout<<i+1<<" "<<1<<endl;

		cout<<1<<" "<<i+n<<endl;
		cout<<i+n<<" "<<i+1+n<<endl;
		i++;
	}


	return 0;
}
