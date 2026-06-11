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
using namespace std;
void add(int& a , int b){
	a += b;
	if(a >= mod) a -= mod;
}
ll mul(ll a , ll b){
	return (a * b) % mod;
}

int main(){
	IOS;
	int n ; cin >> n ;
	if(log2(n) == (int)log2(n)) return cout << "No" <<"\n" , 0 ;
	cout << "Yes" << endl ;
	cout << n + 1 << " " << n + 2 << endl ;
	for(int i = 2 ; i < n ; i += 2){
			cout << 1 << " " << i << "\n" ;
			cout << 1 <<  " " << n + i + 1 << "\n" ;
			cout << i <<" " << i + 1 << "\n" ;
			cout << n + i <<" " << n + i + 1 << "\n" ;
	}
	if(n % 2 == 0){
		for(int i = 2 ; i <= n ; i++){
			if((n ^ i ^ 1) < n){
				if((n ^ i ^ 1) % 2){
					cout << n << " " << i << endl ;
					cout << n  + (n ^ i ^ 1 )<< " " << 2 * n << endl ;
					return 0 ;
				}
				else{
					cout << n << " " << i << endl ;
					cout <<  (n ^ i ^ 1) << " " << 2 * n << endl ;
				}
				return 0 ;
			}
		}
	}
				
		
	
	
	return 0;
}
