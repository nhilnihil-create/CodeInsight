#include <iostream>
#include <string>

using ll=long long int;

constexpr ll mod = 1e9+7;

constexpr int MAX = 1e5+10;

std::string s;

ll pw2[MAX],  pw3[MAX];

void init(){
	pw3[0]=pw2[0]=1;
	for(int i=1;i<MAX;++i){
		pw2[i]=pw2[i-1]*2%mod;
		pw3[i]=pw3[i-1]*3%mod;
	}
}

int main() {

	init();

	ll ans=0;
	int cnt=0;

	std::cin>>s;
	for(int i=0;i<s.size();++i) if(s[i]=='1'){
		ans+=(pw2[cnt]*pw3[s.size()-i-1]%mod);
		ans%=mod;
		++cnt;
	}
	ans=(ans+pw2[cnt])%mod;

	std::cout<<ans<<std::endl;

	return 0;
}
