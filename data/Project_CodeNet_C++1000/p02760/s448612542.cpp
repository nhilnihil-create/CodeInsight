#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define vi vector<int>
#define ii pair<int, int>
#define ll long long int
#define MAX 200010
#define MOD 1e9+7
#define endl '\n'
using namespace std;

int m[3][3];
int mk[3][3];

void mark(int x){
	REP(i, 0, 3){
		REP(j, 0, 3){
			if(m[i][j] == x){
				mk[i][j] = 1;
				return;
			}
		}
	}
}

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	REP(i, 0, 3){
		REP(j, 0, 3){
			cin >> m[i][j];
			mk[i][j] = 0;
		}
	}

	int n;
	cin >> n;

	REP(i, 0, n){
		int x;
		cin >> x;
		mark(x);
	}

	bool bingo = false;
	REP(i, 0, 3){
		int c = 0;
		REP(j, 0, 3){
			if(mk[i][j]) c++;
		}
		if(c == 3){
			bingo = true;
		}
	}

	REP(i, 0, 3){
		int c = 0;
		REP(j, 0, 3){
			if(mk[j][i]) c++;
		}
		if(c == 3){
			bingo = true;
		}
	}

	int i = 0, j = 0;
	int c = 0;
	while(i < 3){
		if(mk[i][j]) c++;
		i++; j++;
	}
	if(c == 3) bingo = true;

	i = 2; j = 0;
	c = 0;
	while(i >= 0){
		if(mk[i][j]) c++;
		i--; j++;
	}
	if(c == 3) bingo = true;

	// REP(i, 0, 3){
	// 	REP(j, 0, 3){
	// 		cout << mk[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	if(bingo){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

    return 0;
}