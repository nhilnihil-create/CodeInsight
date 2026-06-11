#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	int i,j;
	int tmp;
	int answer=0;
	int counter=0;
	vector<int> given;

	cin >> N >> M;

	if(N>0) answer+=N*(N-1);
	if(M>0) answer+=M*(M-1);
	
	cout << answer/2 << endl;

	return 0;
}

