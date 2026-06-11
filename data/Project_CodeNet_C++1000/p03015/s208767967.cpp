
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iterator>
#include <deque>
#include <string>
#include <queue>
#include <omp.h>
#include <fstream>   // ifstream, ofstream
typedef int64_t ll;
using namespace std;
const ll INF=1e10;
#include <cstdint>
#include <iostream>
#include <utility>
#include <map>

int64_t gcd(int64_t a,int64_t b){//calc gcd
	if(a==0){
		return b;
	}else if(b==0){
		return a;
	}else if(a>b){
		return gcd(a%b,b);
	}else{
		return gcd(b%a,a);
	}
}
std::pair<int64_t,int64_t> extgcd(int64_t a,int64_t b){//a*(pair->first) + b*(pair->second) = gcd(a,b)
	if(a==0){
		return std::make_pair(0,1);
	}else if(b==0){
		return std::make_pair(1,0);
	}else{
		if(a>b){
			std::pair<int64_t,int64_t> d=extgcd(a%b,b);
			return std::make_pair(d.first,d.second-(a/b)*d.first);
		}else{
			std::pair<int64_t,int64_t> d=extgcd(a,b%a);
			return std::make_pair(d.first-(b/a)*d.second,d.second);
		}
	}

}
int64_t inline normalize_mod(int64_t a,int64_t m){
	return (m+a%m)%m;
}
int64_t mod_inv(int64_t a,int64_t m){//a^-1(mod m),m is a prime number
	int64_t raw=extgcd(a,m).first;
	return normalize_mod(raw,m);;
}
std::map<int64_t,int64_t> factorization(int64_t n){
	std::map<int64_t,int64_t> retval;
	for(int64_t i=2;i*i<=n;i++){
		int64_t counter=0;
		while(n%i==0){
			n=n/i;
			counter++;
		}
		if(counter!=0){
			retval.emplace(i,counter);
		}
	}
	return retval;
}
std::pair<int64_t,int64_t> mod_fact(int64_t n,int64_t m){//n!=first*m^second
	if(n==0){
		return std::make_pair(1,0);
	}else{

		std::pair<int64_t,int64_t> d=mod_fact(n/m,m);
		int64_t second=d.second+n/m;
		int64_t first;
		if((n/m)%2==0){
			first=1;
		}else{
			first=m-1;
		}
		for(int64_t i1=1;i1<=(n%m);i1++){
			first=normalize_mod(first*i1,m);
		}
		return std::make_pair(first,second);
	}
}


int main(){
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	ll *a=new ll[s.size()];
	ll *b = new ll[s.size()];
	a[0]=3;
	if(s[0]=='0'){
		b[0]=1;
	}else{
		b[0]=3;
	}
	for(ll i1=1;i1<s.size();i1++){
		a[i1]=normalize_mod(3*a[i1-1],1e9+7);
		if(s[i1]=='0'){
			b[i1]=b[i1-1];
		}else{
			b[i1]=normalize_mod(a[i1-1]+2*b[i1-1],1e9+7);
		}
	}
	cout<<b[s.size()-1]<<endl;
}
