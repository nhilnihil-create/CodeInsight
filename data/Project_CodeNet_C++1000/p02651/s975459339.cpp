#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i,n) for(int i=0;i<(lint)(n);i++)
#define REP(i,n) for(int i=1;i<=(lint)(n);i++)
#define all(V) V.begin(),V.end()
#define lint long long
typedef std::pair<lint, lint> P;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;
constexpr double eps = DBL_EPSILON;
constexpr double PI=3.141592653589793238462643383279;
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
inline lint gcd(lint a, lint b) {
	while (b) {
		lint c = a;
		a = b; b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) {
	return a / gcd(a, b) * b;
}
bool isprime(lint n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
template<typename T>
T mypow(T a, unsigned int b) {
	if (!b)return T(1);
	if (b & 1)return mypow(a, b - 1) * a;
	T memo = mypow(a, b >> 1);
	return memo * memo;
}
lint modpow(lint a, lint b, lint m) {
	if (!b)return 1;
	if (b & 1)return modpow(a, b - 1, m) * a % m;
	lint memo = modpow(a, b >> 1, m);
	return memo * memo % m;
}
template<typename T>
void printArray(std::vector<T>& vec) {
	rep(i, vec.size() - 1)std::cout << vec[i] << " ";
	std::cout << vec.back() << std::endl;
}
template<typename T>
void printArray(T l, T r) {
	T rprev = r;
	rprev--;
	for (T i = l; i != rprev; i++) {
		std::cout << *i << " ";
	}
	std::cout << *rprev << std::endl;
}
lint t,n,a[100010];
std::string s;
std::vector<lint> vec;
void basis(){
	int now=0;
	for(int i=60;i>=0;i--){
		for(int j=now;j<vec.size();j++){
			if(vec[j]&((lint)1<<i)){
				std::swap(vec[now],vec[j]);
				break;
			}
		}
		if(vec[now]&((lint)1<<i)){
			for(int j=now+1;j<vec.size();j++){
				if(vec[j]&((lint)1<<i))vec[j]^=vec[now];
			}
			now++;
		}
	}
}
bool check(lint x){
	for(lint i:vec){
		chmin(x,x^i);
	}
	return x==0;
}
int main(){
	std::cin>>t;
	rep(_,t){
		vec.clear();
		std::cin>>n;
		rep(i,n)std::cin>>a[i];
		std::cin>>s;
		for(int i=n-1;i>=0;i--){
			if(s[i]=='0'){
				vec.push_back(a[i]);
				basis();
			}
			else if(!check(a[i])){
				std::cout<<1<<std::endl;
				goto end;
			}
		}
		std::cout<<0<<std::endl;
		end:;
	}
	return 0;
}