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
	
	auto it = find(s.begin(), s.end(), X);
	int idx = it - s.begin();
	int sum = accumulate(t.begin()+idx+1, t.end(), 0);
	
	cout<<sum;

	
	
	return 0;
}