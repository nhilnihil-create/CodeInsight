#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i,j;
	int answer=0;
	ll N;
	ll counter=0;
	string tmp;
	vector<string> given;

	cin >> N;

	for(i=0;i<N;i++){
		cin >> tmp;
		given.push_back(tmp);
	}

	sort(given.begin(),given.end());
	given.erase(unique(given.begin(),given.end()),given.end());
	//sort(given.begin(),given.end(),greater<int>());
	
	answer=given.size();
	cout << answer << endl;

	return 0;
}

