#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
#define MAXN 10000005
int spf[MAXN]; 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 
long long numFactors(int n){
	vector<int> v = getFactorization(n);
	long long p = 1, c = 1;
	for(int i = 1; i < v.size(); i++){
		if(v[i] == v[i-1])
			c++;
		else{
			p *= c + 1;
			c = 1;
		}
	}
	p *= c + 1;
	return p;
}
signed main(){
	sieve();
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 2; i <= n; i++){
		long long t = spf[i] == i ? 2 : numFactors(i);
//		cout << t << endl;
		ans += t * i;
	}
	cout << ans + 1;
	return 0;
}