#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 3;
#define F first
#define S second
ll n , x , y , X , Y;
pair<ll, ll> A[2*N];
pair<ll, ll> prefix[2*N];

int quad(pair<ll,ll> &a){
	if(a.F >= 0 && a.S >= 0)
		return 1;
	else if(a.F < 0 && a.S >= 0)
		return 2;
	else if(a.F < 0 && a.S < 0)
		return 3;
	else
		return 4;
}
ll cross(pair<ll, ll> &a , pair<ll, ll> &b){
	return (a.F*b.S - a.S*b.F);
}
bool cmp(pair<ll,ll> &a , pair<ll, ll> &b){
	if(quad(a) == quad(b))
		return cross(a , b) > 0;
	else
		return quad(a) < quad(b);
}

long double ans = 0;
long double dis(pair<ll, ll> a , pair<ll, ll> b){
	ll some = (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);

	return sqrt(some);
}
int main(){
	cin >> n;
	for(int i= 1 ;i <=n ; i++){
		cin >> A[i].F >> A[i].S;
	}

	sort(A+1 , A+n+1 , cmp);

	// Iterating on the first one to be taken
	for(int i= 1 ;i <= n ; i++)
		A[i+n] = A[i];

	for(int i = 1 ;i <= 2*n ; i++){
		X += A[i].F;
		Y += A[i].S;
		prefix[i] = make_pair(X , Y);
	}
	
	for(int i =1 ;i <= n ; i++){
		for(int j = i ; j < n+i ; j++){

			ans = max(ans , dis(prefix[j] , prefix[i-1]));
		}
	}

	printf("%0.20lf\n", (double)ans );

}