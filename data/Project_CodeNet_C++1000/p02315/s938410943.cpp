#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Knapsack(int N,int W, vector<int> v, vector<int> w)
{
	vector< vector<int> > V(N+1,vector<int>(W+1));
	for(int i=0;i<=N;++i)
		for (int j = 0; j <= W; ++j) {
			if (i == 0 || j == 0) V[i][j] = 0;
			else if (j >= w[i - 1]) V[i][j] = max(v[i - 1] + V[i - 1][j - w[i - 1]], V[i - 1][j]);
			else V[i][j] = V[i - 1][j];
		}
	return V[N][W];
}
int main()
{
	int N, W,vv,ww;
	vector<int> v, w;
	cin >> N >> W;
	for (int variable = 0; variable < N; ++variable) {
		cin >> vv >> ww;
		v.push_back(vv);
		w.push_back(ww);
	}
	cout << Knapsack(N, W, v, w) << endl;
}