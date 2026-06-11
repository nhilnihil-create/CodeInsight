#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

ll mod=1000000007;

int main() {
	int N;
	string S;
	cin >> N >> S;
	if(S[0]=='W' || S[N*2-1]=='W'){
	    cout << 0 << endl;
	    return 0;
	}
	vector<int> v(N*2, 1);
	ll ans=1, now=1;
	for(int i=1; i<N*2; ++i){
	    if(S[i-1]==S[i]) v[i]=-v[i-1];
	    else v[i]=v[i-1];
	    if(v[i]<0){
	        if(now==0){
	            cout << 0 << endl;
	            return 0;
	        }
	        ans=(ans*now)%mod;
	    }
	    now += v[i];
	}
	if(now!=0){
	    cout << 0 << endl;
	    return 0;
	}
	for(int i=1; i<=N; ++i) ans=(ans*i)%mod;
	cout << ans << endl;
	return 0;
}
