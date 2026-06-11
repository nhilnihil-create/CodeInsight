#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	ll i,j;
	int tmp;
	int counter=0;
	ll answer=0;
	vector<int> given;

	cin >> N;

	for(i=1;i<=N;i++){
		if(i%3 && i%5) answer+=i;
	}

	cout << answer << endl;

	return 0;
}

