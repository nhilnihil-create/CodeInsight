#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

struct pair_hash{
	template <typename T1, typename T2>
		size_t operator() (const pair<T1, T2> &p) const
			{return hash<T1>()(p.first) ^ hash<T2>()(p.second);}
};

int N, x[55], y[55], ans = 0;
unordered_map<pair<int, int>, int, pair_hash> mp;

int main(){
	getint(N);
	for(register int i = 1; i <= N; i++) getint(x[i]), getint(y[i]);
	for(register int i = 1; i <= N; i++)
		for(register int j = 1; j <= N; j++) if(i != j)
			ans = max(ans, ++mp[make_pair(x[i] - x[j], y[i] - y[j])]);
	return printf("%d\n", N - ans), 0;
}
