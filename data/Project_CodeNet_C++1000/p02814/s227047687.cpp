#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define INF INT_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)

ll gcd(ll m, ll n){
	ll a;

	while(m % n != 0){
		a = n;
		n = m % n;
		m = a;
	}
	return n;
}


ll lcm(ll m, ll n){
	return m * n / gcd(m,n);
}


int main(){
	ll N,M;

	vector<ll> arr;

	cin>>N>>M;

	arr.resize(N);
	for(auto& s : arr){
		cin>>s;
	}



	//2dewareru kazu

	int count = 0;

	ll tmp = arr[0];
	while(tmp % 2 == 0){
		count++;
		tmp /= 2;
	}
	//cout<<"c : "<<count<<endl;

	bool res = true;
	for(int i = 1; i < N; i++){
		int now_count = 0;
		ll tmp = arr[i];
		while(tmp % 2 == 0){
			now_count++;
			tmp /= 2;
		}
		//cout<<"nc: "<<now_count<<endl;
		res = res && (count == now_count);
	}

	if(res){

		ll lcm_arr = 1;
		REP(i,N){
			lcm_arr = lcm(arr[i] / 2,lcm_arr);
			if(lcm_arr > M){
				cout<<0<<endl;
				return 0;
			}
		}

		ll ans = (M / lcm_arr);

		if(ans % 2 == 0){
			cout<<ans / 2 <<endl;
		}
		else{
			cout<<ans/2 + 1<<endl;
		}


	}
	else{
		cout<<0<<endl;
		//cout<<"gusu"<<endl;
	}
	return 0;
}

