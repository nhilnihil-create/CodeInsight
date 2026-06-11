#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mpair make_pair
#define pm(first, second) pb(mpair(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()
#define reall(X) (X).rbegin(), (X).rend()
#define divcel(a, b) (((a) + ((b) - 1)) / (b))

int main(){

	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for(int i = 0; i < H; i++){
		cin >> S[i];
	}
	vector<vector<int>> V(H, vector<int>(W, 0));
	if(S[0][0] == '#')V[0][0] = 1;
	int a, b;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(i == 0 && j == 0)continue;
			if(i == 0){
				V[i][j] = V[i][j-1];
				if(S[i][j-1] == '.' && S[i][j] == '#')V[i][j]++;
			}
			else if(j == 0){
				V[i][j] = V[i-1][j];
				if(S[i-1][j] == '.' && S[i][j] == '#')V[i][j]++;
			}
			else{
				a = V[i][j-1];
				if(S[i][j-1] == '.' && S[i][j] == '#')a++;
				b = V[i-1][j];
				if(S[i-1][j] == '.' && S[i][j] == '#')b++;
				V[i][j] = min(a, b);
			}
		}
	}
	cout << V[H-1][W-1] << endl;

	return 0;
}
