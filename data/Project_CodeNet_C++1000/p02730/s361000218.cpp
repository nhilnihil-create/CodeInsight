#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;
const ll mininf = -9223372036854775807;
const ll nax = 0;
string a;

bool cek(string s){
	int l=0;
	int r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}

int main(){
	IOS
	cin >> a;
	int n=a.length();
	string b, c;
	for(int i=0;i<(n-1)/2;i++){
		b=b+a[i];
	}
	for(int i=(n+3)/2-1;i<n;i++){
		c=c+a[i];
	}
	bool satu=cek(a);
	bool dua=cek(b);
	bool tiga=cek(c); 
	if(satu&dua&tiga){
		cout << "Yes" << '\n';
	}
	else{
		cout << "No" << '\n';
	}
}