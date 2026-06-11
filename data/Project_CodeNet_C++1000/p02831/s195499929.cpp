#include <bits/stdc++.h>
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
	int A,B;
	cin >> A >> B;
	ll n = A;
	while(1){
		if(n%B == 0){
			cout << n << endl;
			return 0;
		}
		n += A;
	}
}