#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,int>
#define pli std::pair<ll,int>
#define pil std::pair<int,ll>
#define psi std::pair<string,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define vpi std::vector<std::pair<int,int>>
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define vvpil std::vector<std::vector<std::pair<int,ll>>>
#define vlpii std::vector<std::list<pii>>
#define vlpil std::vector<std::list<pil>>
#define li std::list<int>
#define lpil std::list<pil>
#define Endl printf("\n")
#define vli vector<list<int>>
#define vvll vector<vector<ll>>
#define mp make_pair
#define x first
#define y second
#define ma 100000000
#define imie(...) "[" << #__VA_ARGS__": " << (__VA_ARGS__) << "] "
const ll  INF=10000000000000;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9 ;
using namespace std;
void add(ll& a , ll b){
	a += b;
	if(a >= mod) a -= mod;
}
ll mul(ll a , ll b){
	return (a * b) % mod;
}
ll Pow(ll a , ll b){
	if(b == 0) return 1 ;
	ll c = Pow(a , b / 2) ;
	if(b % 2) return (a * ((c * c) ));
	return (c * c) ;
}
const int N = 1e5 + 10, LOG_A = 61;

ll basis[LOG_A];

void insertVector(ll mask) {
	for (int i = LOG_A - 1; i >= 0; i--) {
		if ((mask & Pow(2 , i)) == 0) continue;

		if (!basis[i]) {
			basis[i] = mask;
			return;
		}

		mask ^= basis[i];
	}
}
int main(){
	IOS;
	cout.precision(50) ;
	int n ; cin >> n ;vll a(n);for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	vi b(61 , 0) ;
	for(ll i = 0 ; i < 61 ; i++){
		for(int  j = 0 ; j < n ; j++){
			if(a[j] & Pow(2 , i)) b[i]++ ;
		}
	}
	for(ll i = 0 ; i < 61 ; i++){
		if(b[i] % 2){
			for(int j = 0 ; j < n ; j++){
				if(a[j] & Pow(2 , i)) a[j] ^= Pow(2 , i) ;
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		insertVector(a[i]) ;
	}
	ll ans = 0 ;
	for (int i = LOG_A - 1; i >= 0; i--) {
		if (!basis[i]) continue;
		if (ans & Pow(2 , i)) continue;

		ans ^= basis[i];
	}
	ans *= 2 ;
	for(ll i = 0 ; i < 61 ; i++) if(b[i] % 2) ans += Pow(2 , i) ;
	cout << ans << endl ;
	
	return 0;
}
