#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;

struct Req{
	int Ai;
	int Bi;
	int ans;
	int point;
};

int N,M,Q;
int answer=0;
vector<int> A;
vector<Req> given;

int dfs(vector<int> A){ 
/*
	for(auto itr:A)
		cout << itr << " ";
	cout << endl;
*/

	if(A.size() == N+1){ int counter=0;
		for(auto g:given)
			if(A[g.Bi] - A[g.Ai] == g.ans) counter+=g.point;

		return counter;
	}

	A.push_back(A.back());
	while(A.back()<=M){
		answer=max(answer,dfs(A));
		A.back()++;
		//cout << "ANS>>>>>>>>>>>>>>>>>>>>>>>>>" << answer << endl;
	}

	return answer;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i;
	struct Req tmp;

	cin >> N >> M >> Q;

	for(i=0;i<Q;i++){
		cin >> tmp.Ai >> tmp.Bi >> tmp.ans >> tmp.point;
		given.push_back(tmp);
	}

	A.resize(1,1);
	dfs(A);

	cout << answer << endl;

	return 0;
}
