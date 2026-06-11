#include <bits/stdc++.h>
using namespace std;
#define pb push_back
string s;
long long k , len , sol , sum;
char c;
vector<long long>v;
int main(){
	cin >> s;
	cin >> k;
	c = s[0];
	sum = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == c){
			len++;
		}
		if(s[i] != c || i == s.size() - 1){
			v.pb(len);
			len = 1;
			c = s[i];
		}
	}
	if(v.size() == 1){
		sum = v[0];
		sol = (sum*k)/2;
	}
	else if(s[0] == s[s.size() - 1]){
		for(int i = 1 ; i < v.size() - 1 ; i++){
			sol += v[i]/2;
		}
		sol *= k;
		sum += (v[0] + v[v.size() - 1])/2;
		sum *= (k - 1);
		sol += sum;
		sol += (v[0]/2) + (v[v.size() - 1]/2);
	}
	else{
		for(int i = 0 ; i < v.size() ; i++){
			sol += v[i]/2;	
		}
		sol *= k;
	}
	cout << sol << endl;
}