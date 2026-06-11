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
#define all(x) (x).begin(), (x).end()
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

int main(){
	int n; cin>>n;
	int odd=0,eve=0;
	rep(i,1,n+1){
		if(i%2==1) odd++;
		else eve++;
	}

	cout<<double((odd+0.0)/(n+0.0))<<endl;

	return 0;
}