#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main(){
	int N;
	cin >> N;
	vector<string> s(N);
	vector<int> t(N);
	
	for (int i=0; i<N; i++){
		cin>>s[i];
		cin >> t[i];		
	}
	
	string X;
	cin >> X;
	
	bool flag = false;
	int sum = 0;
	for (int i=0; i<N; i++){
		if (flag) sum += t[i];
		if (s[i] == X){
			flag = true;			
		}		
	}
	cout<<sum;

	
	
	return 0;
}