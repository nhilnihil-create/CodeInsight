#include <bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	list<int> l;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		int k;
		cin >> s;
		if(s == "insert"){
			cin >> k;
			l.emplace_front(k);
		}else if(s == "delete"){
			cin >> k;
			auto it = find(l.begin(),l.end(),k);
			if(it == l.end())continue;
			l.erase(it);
		}else if(s == "deleteFirst"){
			l.pop_front();
		}else{
			l.pop_back();
		}
	}

	for(auto it=l.begin();it!=l.end();it++){
		cout << *it;
		if(it != --l.end()){
			 cout << " ";
		}
	}
	cout << endl;

	return 0;
}