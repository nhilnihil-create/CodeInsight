#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111




	void solve(){


		ini(n);
		int morty[n];
		int morty1[n];
		int rick = 0;
		FOR(i,0,n)in(morty[i]);
		priority_queue<pair<int,int> > tmp;
		FOR(i,0,n){
			in(morty1[i]);
			if(morty1[i]>morty[i]){
				tmp.push(make_pair(morty1[i],i));
			}
		}
		while(tmp.size()){
			pair<int,int> tmp1;
			tmp1 = tmp.top();
			tmp.pop();
			if(tmp1.first > morty1[tmp1.second-1==-1?(n-1):tmp1.second-1]+morty1[tmp1.second+1 == n?0:tmp1.second+1]){
				if((morty1[tmp1.second]-morty[tmp1.second])%(morty1[tmp1.second-1==-1?(n-1):tmp1.second-1]+morty1[tmp1.second+1 == n?0:tmp1.second+1]) == 0){
					rick+=(morty1[tmp1.second]-morty[tmp1.second])/(morty1[tmp1.second-1==-1?(n-1):tmp1.second-1]+morty1[tmp1.second+1 == n?0:tmp1.second+1]);
					morty1[tmp1.second] = morty[tmp1.second];
				}
				else{
					morty1[tmp1.second] = tmp1.first%(morty1[tmp1.second-1==-1?(n-1):tmp1.second-1]+morty1[tmp1.second+1 == n?0:tmp1.second+1]);
					rick+=tmp1.first/(morty1[tmp1.second-1==-1?(n-1):tmp1.second-1]+morty1[tmp1.second+1 == n?0:tmp1.second+1]);
					if(morty1[tmp1.second]<morty[tmp1.second])return out(-1);
					tmp.push(make_pair(morty1[tmp1.second],tmp1.second));
				}
				
			}
			else{
				return out(-1);
			}
			
		}
		out(rick);
		


	}























int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}
