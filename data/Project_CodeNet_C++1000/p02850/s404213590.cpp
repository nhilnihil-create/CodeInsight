#include <bits/stdc++.h>
#include <math.h>

using namespace std;

template<typename T>
long long modpow(const T n,const T p,const T mod);
template<typename T>
long long modinv(const T n,const T mod);
template<typename T>
bool chmax(T &a,const T &b);
template<typename T>
bool chmin(T &a,const T &b);

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	vector<vector<long long>> tyoten(n);
	vector<long long> hen(n-1,0);
	vector<pair<long long,long long>> connect(n-1);
	vector<set<long long>> tyotencol(n);

	for(long long i=0;i<n-1;i++){
		long long a,b;
		cin>>a>>b;
		a--;b--;
		tyoten.at(a).push_back(i);
		tyoten.at(b).push_back(i);

		connect.at(i).first=a;
		connect.at(i).second=b;
	}

	long long k=-1;

	for(auto a:tyoten){
		chmax(k,(long long)a.size());
	}

	cout<<k<<endl;

	for(long long i=0;i<n;i++){
		long long color=1;
		for(long long j=0;j<tyoten.at(i).size();j++){
			while(true){
				long long presize=tyotencol.at(i).size();
				tyotencol.at(i).insert(color);
				if(presize!=tyotencol.at(i).size()) break;
				color++;
			}

			if(hen.at(tyoten.at(i).at(j))==0){
				hen.at(tyoten.at(i).at(j))=color;
				tyotencol.at(connect.at(tyoten.at(i).at(j)).first).insert(color);
				tyotencol.at(connect.at(tyoten.at(i).at(j)).second).insert(color);
			}else{
				tyotencol.at(i).erase(color);
			}
		}
	}

	for(auto a:hen) cout<<a<<endl;

	return 0;
}

template<typename T>
long long modpow(const T n,const T p,const T mod){
	if(p==0) return 1;
	if(p%2==0){
		long long a=modpow(n,p/2,mod);
		return a*a%mod;
	}
	if(p%2==1) return (modpow(n,p-1,mod)*n)%mod;
	cerr<<"ERROR"<<endl;
	return 1;
}

template<typename T>
long long modinv(const T n,const T mod){
	return modpow(n,mod-2,mod);
}

template<typename T>
bool chmax(T &a,const T &b){
	if(a<b){
		a=b;
		return 1;
	}
	return 0;
}

template<typename T>
bool chmin(T &a,const T &b){
	if(a>b){
		a=b;
		return 1;
	}
	return 0;
}
