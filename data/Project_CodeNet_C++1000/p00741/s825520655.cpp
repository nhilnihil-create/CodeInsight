
using namespace std;

static const int N = 52;

void dfs(int map[][N], int pi, int pj){
	const int di[] = {-1,0,1,1,1,0,-1,-1};
	const int dj[] = {1,1,1,0,-1,-1,-1,0};

	if( map[pi][pj] == 0 ){
		return ;
	}

	map[pi][pj] = 0;

	for(int i = 0; i < sizeof(di)/sizeof(di[0]); i++){
		dfs(map, pi + di[i], pj + dj[i] );
	}
}

int main(void){
	ws(cin);
	while( 1 ){
		int count = 0;
		int n, m;
		int map[N][N] = {{0,},};

		cin >> n >> m;
		if( n == 0 && m == 0 ){
			break;
		}

		for(int i = 0; i < m; i++ ){
			for(int j = 0; j < n; j++){
				cin >> map[j + 1][i + 1];
			}
		}

		for(int i = 0; i < m; i++ ){
			for(int j = 0; j < n; j++){
				if(map[j + 1][i + 1]){
					dfs(map, j + 1, i + 1);
					count++;
				}
			}
		}

		cout << count << "\n";
	}
	return 0;
}