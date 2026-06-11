#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

const ll MOD = 1000000007;
const ll MAX = 2000001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  
  ll n; string str; cin >> n >> str;
  
  ll cnt = 0;
  
  std::ios::fmtflags curret_flag = std::cout.flags();
	
	for(ll i=0; i < 1000; i++){
      //123の頭に5個0を詰めて8桁にする
	std::ostringstream ss;
	ss << std::setw(3) << std::setfill('0') << i << "\n";
	std::string s(ss.str());
 
      ll now = 0;
    for(ll j=0; j < n; j++){
      if(str[j] == s[now]){
        now++;
        if(now == 3){
          cnt++;
          break;
        }
      }
    }
    }
	// 戻し
	std::cout.flags(curret_flag);
      
      cout << cnt << endl;
}
