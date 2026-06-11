#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = ((B)-1); I >= (A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define pri(a) cout << (a) << endl

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(1){
		getline(cin,s);
		if(s==".")break;
		stack<char> st;
		bool ans = true;
		FOR(i,0,s.size()){
			if(s[i]=='('||s[i]=='['){
				st.push(s[i]);
			}else if(s[i]==')'){
				if(st.size()==0){
					ans = false;
				}else{
					if(st.top()=='(')st.pop();
					else ans = false;
				}
			}else if(s[i]==']'){
				if(st.size()==0){
					ans = false;
				}else{
					if(st.top()=='[')st.pop();
					else ans = false;
				}	
			}
		}
		if(st.size()!=0)ans = false;
		if(ans){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}
}
