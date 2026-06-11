//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
multiset<int> s,now;
int main(){
	int n;
	int odn;
	cin>>n;
	odn=n;
	n=1<<n;
	rb(i,1,n) {
		int ai;
		cin>>ai;
		s.insert(-ai);
	}
	multiset<int> :: IT ite;
	now.insert(-*s.begin());
	rb(i,1,odn){
		multiset<int> save=now;
		for(auto it : now){
			ite=s.upper_bound(-it);
			if(ite==s.end()){
				puts("No");
				return 0;
			} 
			else{
				save.insert(-*ite);
				s.erase(ite);
			}
		}
		now=save;
	}
	puts("Yes");
	return 0;
}