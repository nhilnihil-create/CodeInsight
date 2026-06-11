#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N,A,B;
	int i,j;
	int tmp;
	ll answer=0;
	int counter=0;
	vector<int> given;

	cin >> N >> A >> B;

	answer+=(N/(A+B))*A;

	if(N%(A+B)<A)
		answer+=N%(A+B);
	else
		answer+=A;
	
	cout << answer << endl;

	return 0;
}

