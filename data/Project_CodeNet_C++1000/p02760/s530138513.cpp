#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 45+10;
const int mod = 1e9+7;

using namespace std;

bool ok[4][4];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int g[4][4];

	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			cin >> g[i][j];
		}
	}

	int n;

	cin >> n;

	for(int i=0,x;i<n;++i){
		cin >> x;
		for(int r=1;r<=3;++r){
			for(int c=1;c<=3;++c){
				if(g[r][c] == x) ok[r][c] = 1;
			}
		}
	}

	int yes;

	yes = (ok[1][1] && ok[2][2] && ok[3][3]);

	yes |= (ok[3][1] && ok[2][2] && ok[1][3]);

	yes |= (ok[1][1] && ok[1][2] && ok[1][3]);
	yes |= (ok[2][1] && ok[2][2] && ok[2][3]);
	yes |= (ok[3][1] && ok[3][2] && ok[3][3]);

	yes |= (ok[1][1] && ok[2][1] && ok[3][1]);
	yes |= (ok[1][2] && ok[2][2] && ok[3][2]);
	yes |= (ok[1][3] && ok[2][3] && ok[3][3]);



	cout << (yes ? "Yes" : "No") << endl;

    return 0;
}

