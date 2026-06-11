#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;

template <class _T> inline bool chmax (_T& a,_T b){if(a<b){a=b;return true;}return false;}
template <class _T> inline bool chmin (_T& a,_T b){if(a>b){a=b;return true;}return false;}

const long long INF = 1LL << 60;
const long long mod = 1000000007;


int main(void){
    string s;cin >> s;
    ll k; cin >> k;
    char p='A';ll n=0;
    bool even = false; 
    for(int i=0;i<s.length();i++){
	if(p == s[i] && !even){
	    n++;
	    even = true;
	}else{
	    even = false;
	    p = s[i];
	}
    }
    int a=1,b=1; char c=s[0],d=s[s.size()-1];
    if(c != d){
	cout << n*k << endl;
	return 0;
    }
    for(int i=1;i<s.size();i++){
	if(c==s[i])a = 1-a;
	else break;
    }
    for(int i=s.size()-2;i>=0;i--){
	if(d==s[i])b = 1-b;
	else break;
    }
    int q;
    for(q=0;q<s.size()-1;q++){
	if(s[q]!=s[q+1]) break;
    }
    if(q==s.size()-1 && s.size()%2==1){
	cout << (s.size()*k)/2 << endl;
	return 0;	
    }
    if(a==1 && b==1)cout << n*k + k - 1 << endl; 
    else cout << n*k << endl;
    return 0;
}
