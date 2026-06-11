//Har Har Mahadev
using namespace std;
#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
#define pb push_back
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " -> " << a << endl;
	err(++it, args...);
}
map<string,int> in;
void testcase(){
	int n;
	cin >> n;
	string p,q,cor;
	for(int i{0};i < n;i++){
		char c;
		cin >> c;
		p += c;
		cor += '1' + i;
	}
	for(int i{0};i < n;i++){
		char c;
		cin >> c;
		q += c;
	}
	int i{2};
	in[cor] = 1;
	while(next_permutation(cor.begin(),cor.end())){
		in[cor] = i++;
	}
	cout << abs(in[p] - in[q]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--){
		testcase();
	}
	return 0;
}
