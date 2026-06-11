#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector <ll> vec;

void findDuplicate(string s, ll n){
	ll counter = 0;
  	ll left = 0, right = 0; 

	while(left < s.size()){
		while(right < s.size() && s[right] == s[right+1])
			right++; 
		vec.push_back(right - left + 1);
		left = right + 1; 
		right = left; 
  	}
}

void solve(string s, ll n){
	ll answer = 0; 
	for(ll i = 0; i < vec.size(); i++){ 
	    answer += vec[i] / 2; 
	}

  if(vec[0] == s.size()){
	   cout << (s.size()*n) / 2 << endl; 
	   exit(0);
	 }

	if(vec[0] % 2 == 1 && vec.back() % 2 == 1 && s[0] == s[s.size() - 1]){
		cout << n * answer + n - 1 << endl; 
		exit(0);
	}
	cout << n * answer << endl; 
}

int main(){
	string s;
	ll n;

	cin >> s >> n; 

  	findDuplicate(s , n);
	solve(s , n);
}

// First, last letter are same, if odd occurence increase answer by n-1
