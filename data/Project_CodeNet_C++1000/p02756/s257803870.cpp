#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	string s;
	cin >> s;
	int q;
	cin >> q;
	list<char> L_front(0);
	list<char> L_back(0);
	bool rev = false;
	rep(i, q){
		int x, f;
		cin >> x;
		if(x== 1){
			if(rev) rev = false;
			else rev = true;
		}
		if(x == 2){
			char c;
			cin >> f >> c;
			if(!rev){
				if(f == 1) L_front.push_front(c);
				if(f == 2) L_back.push_back(c);
			}else{
				if(f == 1) L_back.push_back(c);
				if(f == 2) L_front.push_front(c);
			}
		}
	}
	if(rev){
		auto itr1 = L_front.end();
		auto itr2 = L_back.end();
		reverse(s.begin(), s.end());
		while(1){
			itr2--;
			cout << *itr2;
			if(itr2 == L_back.begin()) break;
		}
		cout << s;
		while(1){
			itr1--;
			cout << *itr1;
			if(itr1 == L_front.begin()) break;
		}
		cout << endl;
	}else{
		auto itr1 = L_front.begin();
		auto itr2 = L_back.begin();
		while(itr1 != L_front.end()){
			cout << *itr1;
			itr1++;
		}
		cout << s;
		while(itr2 != L_back.end()){
			cout << *itr2;
			itr2++;
		}
		cout << endl;
	}
}
