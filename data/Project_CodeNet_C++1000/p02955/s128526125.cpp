#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;

//ll mod = 1000000007 ;
//long double pie = acos(-1) ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void mysort(vector<long long> &a){sort(a.begin(),a.end()) ;}
void myrev(vector<long long> &a){reverse(a.begin(),a.end()) ;}

bool check(vll &a,ll div,ll k){
	if(div==2){
		ll sum = 0 ;
		for(int i=0;i<a.size();i++) sum += (a.at(i)&1) ;
		return (sum/2<=k) ;
	}else{
		vll mn,mx ;
		ll mnsum=0,mxsum=0 ;
		for(int i=0;i<a.size();i++){
			ll d = a.at(i)%div ;
			if(d<=div/2){
				mn.emplace_back(d) ;
				mnsum += d ;
			}else{
				mx.emplace_back(div-d) ;
				mxsum += div-d ;
			}
		}
		if(mnsum<mxsum){
			ll res = mnsum ;
			mxsum -= mnsum ;
			mysort(mx) ;
			ll cnt = 0 ;
			for(int i=mx.size()-1;i>=0;i--){
				if(mxsum==cnt) break ;
				res += div-mx.at(i) ;
				cnt += div ;
			}
			return (res<=k) ;
		}else{
			ll res = mxsum ;
			mnsum -= mxsum ;
			mysort(mn) ;
			ll cnt = 0 ;
			for(int i=mn.size()-1;i>=0;i--){
				if(mnsum==cnt) break ;
				res += div-mn.at(i) ;
				cnt += div ;
			}
			return (res<=k) ;
		}
	}
}

int main(){
	ll n,k ;
	cin >> n >> k ;
	vll a(n) ;
	ll sum = 0 ;
	for(int i=0;i<n;i++){
		cin >> a.at(i) ;
		sum += a.at(i) ;
	}
	vll div ;
	for(ll i=1;i*i<=sum;i++){
		if(sum%i==0){
			div.push_back(i) ;
			div.push_back(sum/i) ;
		}
	}
	mysort(div) ; myrev(div) ;
	for(int i=0;i<div.size();i++){
		if(check(a,div.at(i),k)){
			cout << div.at(i) << endl ;
			return 0 ;
		}
	}
}
