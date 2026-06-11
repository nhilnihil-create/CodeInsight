#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
#define rep(i, a, b) for(lli i = a; i < (b); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) lli((x).size())
#define wis cout<<endl<<"I already speak english, bitch"<<endl<<endl;
 
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef pair<ii,lli> iii;
 
#define trace(args...) { string  _s =#args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);}
void err(istream_iterator<string> it){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
    cout <<  *it  << " : " << a << endl;
    err(++it, args...);
}

vector<lli> factors(lli n) {
  vector<lli> f;
  for (lli x = 2; x*x <= n; x++) {
    while (n%x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}

int main(){
	lli a,b; cin>>a>>b;
	vi A=factors(a),B=factors(b);
	set<lli> f1,f2;
	for(auto x : A) f1.insert(x);
	for(auto x : B) f2.insert(x);
	int cnt=0;
	for(auto x : f1) if(f2.count(x)) cnt++;
	cout<<cnt+1<<endl;
	return 0;
}