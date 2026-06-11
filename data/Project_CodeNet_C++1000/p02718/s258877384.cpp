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
	int counter=0;
	double sum=0;
	double N,M;
	double tmp;
	vector<int> given;

	cin >> N >> M;

	for(i=0;i<N;i++){
		cin >> tmp;
		sum+=tmp;
		given.push_back(tmp);
	}

	for(i=0;i<N;i++)
		if(sum/(4*M) <= given[i]) counter++;

	if(counter<M)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

	return 0;
}

