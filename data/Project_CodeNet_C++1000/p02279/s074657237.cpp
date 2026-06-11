#include<iostream>
#include<string>
#include<set>
#include<utility>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int N;
int parent[100000], Left[100000], Right[100000];
int d[100000];

void rec(int u, int p){
	d[u] = p;
	if(Right[u] != -1) rec(Right[u], p);
	if(Left[u] != -1) rec(Left[u], p+1);
}

void print(int n){
	cout << "node " << n;
	cout << ": parent = "<< parent[n];
	cout << ", depth = "<< d[n] << ", ";
	
	if(parent[n] == -1) cout << "root";
	else if(Left[n] == -1) cout << "leaf";
	else cout << "internal node";

	cout << ", [";

	int c = Left[n];
	for(int i=0; c != -1; i++){
		if(i) cout << ", ";
		cout << c;
		c = Right[c];
	}
	cout << "]" << endl;
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		parent[i] = Left[i] = Right[i] = -1;
	}

	for(int i=0; i<N; i++){
		int id, k, l;
		cin >> id >> k;
		for(int j=0; j<k; j++){
			int c;
			cin >> c;
			if(j == 0){
				Left[id] = c;
			}
			else{
				Right[l] = c;
			}
			l = c;
			parent[c] = id;
		}
	}

	int r;
	for(int i=0; i<N; i++){
		if(parent[i] == -1) r = i;
	}

	rec(r, 0);
	
	for(int i=0; i<N; i++) print(i);

	return 0;
}

//カードゲーム
/*
int main(){
	int N;
	cin >> N;
	vector<int> Taro, Hana;

	for(int i=0; i<N; i++){
		int tmp;
		cin >> tmp;
		Taro.push_back(tmp);
	}
	sort(Taro.begin(), Taro.end());

	for(int i=1; i<=2*N; i++){
		for(int j=0; j<N; j++){
			if(i == Taro[j]){
				break;
			}
			else if(j = N-1){
				Hana.push_back(i);
			}
		}
	}

	int TaroSize = Taro.size();
	int HanaSize = Hana.size();

	bool taroturn = true;
	int now = 0;
	while(TaroSize != 0 && HanaSize != 0){
		if(taroturn){
			for(int i=0; i<TaroSize; i++){
				if(now < Taro[i]){
					now = Taro[i];
					taroturn = false;
				}
			}
		}
		else{

		}
	}

	return 0;
}
*/

//サッカー
/*
int main(){
	int N;
	cin >> N;
	
	int X[4][3] = {};

	for(int i=0; i<N*(N-1)/2; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; 
		b--;

		if(c>d){
			X[a][0]++;
			X[b][1]++;
		}
		if(c == d){
			X[a][2]++;
			X[b][2]++;
		}
		if(c<d){
			X[a][0]++;
			X[b][1]++;
		}
	}


	return 0;
}
*/

//すごろく
/*
int main(){
	int N, M;
	cin >> N >> M;
	
	int Place[1000];
	for(int i=0; i<N; i++){
		cin >> Place[i];
	}

	int ans;
	int now = 0;
	for(int i=0; i<M; i++){
		int sai;
		cin >> sai;

		now += sai;
		now += Place[now];

		if(now >= N-1){
			ans = i + 1;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
*/

//鉛筆
/*
int main(){
	int N, a, b, c, d;
	cin >>  N >> a >> b >> c >> d;
	/*
	int x, y;
	for(int i=1; i*a < N; i++){
		x = i*b;
	}
	for(int i=1; i*c < N; i++){
		y = i*d;
	}

	x += b;
	y += d;*/
	
	/*
	int x = N/a * b;
	if(N%a != 0) x += b;

	int y = N/c * d;
	if(N%c != 0) y += d;
	

	if(x>y) x = y;

	cout << x << endl;

	return 0;
}
*/

/*
int main(){
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int ans = 0;

	if(a<0){
		ans += c * abs(a) + d;
		a = 0;
	}
	
	ans += (b-a)*e;

	cout << ans << endl;

	return 0;
}
*/

/*
//科目選択
int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	if(e < f) e = f;

	int sum = a + b + c + d;

	if(a>b) a = b;
	if(a>c) a = c;
	if(a>d) a = d;

	cout << sum - a + e << endl;

	return 0;
}
*/

//最大の和
/*
int main(){
	while(true){
		int k;
		int A[100000];
		int N;

		cin >> N >> k;
		if(N == 0 && k == 0) break;

		A[0] = 0;
		for(int i=1; i<=N; i++){
			cin >> A[i];
			A[i] = A[i] + A[i-1];
		}

		int ans = -99999999;
		for(int i=1; i+k-1<N; i++){
			ans = max(ans, A[i+k-1] - A[i-1]);
		}

		cout << ans << endl;
	}

	return 0;
}
*/
//フィボナッチ数列
/*
int dp[100];
int N;

int solve(int n){
	if(dp[n] != -1) return dp[n];

	dp[n] = solve(n-2) + solve(n-1);
	return dp[n];
}

int main(){
	cin >> N;

	for(int i=0; i<100; i++){
		dp[i] = -1;
	}
	dp[0] = 1;
	dp[1] = 1;

	cout << solve(N) << endl;

	return 0;
}
*/
/*
//Longest Common Subsequence
int c[1001][1001];

int lcs(string X, string Y){
	int m = X.size();
	int n = Y.size();
	int maxl = 0;

	X = ' ' + X;
	Y = ' ' + Y;

	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			c[i][j] = 0;
		}
	}

	//for(int i=1; i<=m; i++) c[i][0] = 0;
	//for(int i=1; i<=n; i++) c[0][i] = 0;

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(X[i] == Y[j]){
				c[i][j] = c[i-1][j-1] + 1;
			}
			else{
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
			maxl = max(c[i][j], maxl);
		}
	}

	return maxl;
}

int main(){
	int q;
	cin >> q;
	string X, Y;

	for(int i=0; i<q; i++){
		cin >> X >> Y;
		cout << lcs(X, Y) << endl;
	}

	return 0;
}


/*
int main(){

	/*
	int x,y;
	cin >> x >> y;

	cout << x << " + " << y << " = " << x+y << endl;
	cout << x << " - " << y << " = " << x-y << endl;
	cout << x << " * " << y << " = " << x*y << endl;
	cout << x << " / " << y << " = " << x/y << endl;
	cout << x << " % " << y << " = " << x%y << endl;
	*/

	/*
	int p;
	cin >> p;

	if(p<50){
		cout << "Your grade is C" << endl;
	}
	else if(p >= 50 && p < 70){
		cout << "Your grade is B" << endl;
	}
	else if(p >= 70 && p<100){
		cout << "Your grade is A" << endl;
	}
	else if(p == 100){
		cout << "Your grade is S" << endl;
	}
	*/

	/*
	string name;
	double a, b, c, d, f;
	cin >> name >> a >> b >> c >> d >> f;

	double p = (5*a + 4*b + c*3 + d*2 + f)/(a + b + c + d + f);

	cout << name << " ";

	if(p == 5) cout << "Great!" << endl;
	if(p >= 4&& p < 5) cout << "Very Good" << endl;
	if(p >= 3&& p < 4) cout << "Good!" << endl;
	if(p < 3) cout << "Poor!" << endl;
	*/

/*
	int aw, al, ah;
	int bw, bl, bh;
	int cw, cl, ch;
	int dw, dl, dh;
	int ew, el, eh;

	cin >> aw >> al >> ah;
	cin >> bw >> bl >> bh;
	cin >> cw >> cl >> ch;
	cin >> dw >> dl >> dh;
	cin >> ew >> el >> eh;

	int ap = aw - al;
	int bp = bw - bl;
	int cp = cw - cl;
	int ap = dl;w - al;
	int ap = aw - al;

	return 0;
}
*/


//総当り
/*
int N, M;
int A[100];
int dp[100][100];

int solve(int now, int m){
	if(m == 0) return 1;
	if(now >= N) return 0;

	if(dp[now][m] != -1) return dp[now][m];

	if(solve(now+1, m) == 1){
		dp[now][m] = 1;
	}
	else{
		dp[now][m] = solve(now+1, m-A[now]);
	}

	return dp[now][m];
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			dp[i][j] = -1;
		}
	}

	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> M;
		if(solve(0, M) == 1){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}

	return 0;
}
*/
//幅優先探索
/*
int N;
int M[101][101];
queue<int> que;
int cost[101];

void solve(int now){
	for(int i=0; i<N; i++){
		if(M[now][i] == 1){
			if(cost[i] == -1){
				cost[i] = cost[now] + 1;
				que.push(i);
			}
			else if(cost[now] + 1 < cost[i]){
				cost[i] = cost[now] + 1;
				que.push(i);
			}
		}
	}
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		int u, k;
		cin >> u >> k;
		for(int j=0; j<k; j++){
			int v;
			cin >> v;
			M[u-1][v-1] = 1;
		}
	}

	for(int i=0; i<N; i++){
		cost[i] = -1;
	}

	cost[0] = 0;
	que.push(0);
	while (!que.empty())
	{
		solve(que.front());
		que.pop();
	}

	for(int i=0; i<N; i++){
		cout << i+1 << " " << cost[i] << endl;
	}

	return 0;
}
*/
//深さ優先探索
/*
int N;
int M[101][101] = {};
int d[101] = {};
int f[101] = {};
int ct = 0;

void solve(int now){	
	if(d[now] == 0) d[now] = ct;
	for(int i=1; i<=N; i++){
		if(M[now][i] == 1 && d[i] == 0){
			ct++;
			solve(i);
		}
		if(i == N){
			ct++;
			f[now] = ct;
		}
	}
}

int main(){
	cin >> N;

	for(int i=1; i<=N; i++){
		M[0][i] = 1;
	}

	for(int i=0; i<N; i++){
		int u, k;
		cin >> u >> k;
		for(int j=0; j<k; j++){
			int v;
			cin >> v;
			M[u][v] = 1;
		}
	}

	solve(0);

	for(int i=1; i<=N; i++){
		cout << i << " " << d[i] << " " << f[i] << endl;
	}

	return 0;
}
*/

//グラフの表現
/*
int main(){
	int n;
	int M[101][101] = {};
	cin >> n;

	for(int i=0; i<n; i++){
		int u, k;
		cin >> u >> k;
		for(int j=0; j<k; j++){
			int v;
			cin >> v;
			M[u-1][v-1] = 1;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << M[i][j];
			if(j != n-1){
				cout << " ";
			}
			else{
				cout << endl;
			}
		}
	}

	return 0;
}
*/
//二乗法
/*
int main(){
	long long m,n;
	int MOD = 1000000007;
	cin >> m >> n;
	long long ans = 1;
	while(n != 0){
		if(n%2 == 1){
			ans *= m;
			ans %= MOD;
		}
		n = n/2;
		m = m*m;
		m %= MOD;
	}
	cout << ans << endl;

	return 0;
}
*/

//カードゲーム
/*
int n;
bool T[100], H[100];
int Tnum = n, Hnum = n;

int main (){
	cin >> n;
	for(int i=0; i<2*n; i++){
		T[i] = false;
	}

	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		T[a] = true;
	}
	for(int i=0; i<n; i++){
		if(!T[i]){
			H[i] = true;
		}
	}

	int now;
	bool turn = true;
	for(int i=0; i<n; i++){
		if(T[i]){
			now = i;
			T[i] = false;
			Tnum--;
			turn = false;
			break;
		}
	}
	while(Tnum > 0 || Hnum > 0){
		for(int i=0; i<n; i++){
			if(T[i]){
				now = i;
				T[i] = false;
				Tnum--;
				turn = false;
				break;
			}
			else if(H[i]){
				now = i;
				H[i] = false;
				Hnum--;
				turn = true;
				break;
			}
		}
	}
	

	return 0;
}
*/
/*
int A[100];
int B[100];	
int n;
int ansT, ansH;
int taro = n - 1, hana = n;

void solve(int c, bool b){
		if(taro == 0){
			ansT = hana;
			return;
		}
		if(hana == 0 ){
			ansH = taro;
			return;
		}
		if(b){
			for(int i=0; i<n; i++){
				if(c < B[i]){
					int a = B[i];
					B[i] = -1;
					hana--;
					solve( a, !b);
					return;
				}
				else if(i==n-1){
					taro++;
					solve(0 , !b);
				}
			}
		}
		else{
			for(int i=0; i<n; i++){
				if(c < A[i]){
					int a = B[i];
					A[i] = -1;
					taro--;
					solve( a, !b);
					return;
				}
				else if(i==n-1){
					taro++;
					solve(0, !b);
				}
		}
	}
}
int main(){
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}

		for(int i=0; i<n; i++){
			cin >> A[i];
		}
		sort(A, A+n);

		int m = 0;
		for(int i=0; i<n ; i++){
			for(int j=B[m]+1; j<=2*n; j++){
				if(A[i] != j){
					B[m] = j;
					m++;
				}
			}
		}

		solve(A[0], true);

		cout << ansT << endl << ansH << endl;
	}
	return 0;
}
*/

//最高のピザ
/*
int n,a,b,c;
int A[110];
int dp[110][110];

int main(){
	cin >> n >> a >> b >> c;

	for(int i=1; i<=n; i++){
		cin >> A[i];
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + A[i]);
		}
	}

	int ans = c/a;
	for(int i=0; i<=n; i++){
		ans = max(ans, (dp[n][i]+c)/(a + b*i) );
	}

	cout << ans << endl;

	return 0;
}
*/
	/*
	int x = 0;
	dp[0].first = 0;

	for(int j=0; j<n; j++){
		//X.push_back(temp);
		if(dp[j].first < dp[j].first + A[j]){
			dp[j+1].first = dp[j].first + A[j];
			dp[j+1].second = x;
		}
		else{
			dp[j+1] = dp[j];
		}
		//dp.push_back(-1);
	}

	int ans = 0;
	for(int i=0; i<n+1; i++){
		ans = max( (dp[i].first + c)/(dp[i].second * b + a), ans);
	}

	cout << ans << endl;
	*/
	//cout << solve(0) << endl;

//チーズ
/*
int h,w,n;
pair<int,int> factory[10];
int cost[1000][1000];
queue< pair<int,int> > que;
string S[1000];
int A[2][4] = {{-1, 1 ,0, 0}, {0, 0, -1, 1}};

void Solve(pair<int,int> Now){
	for(int i = 0; i<4; i++){
		int x = Now.first + A[0][i];
		int y = Now.second + A[1][i];
		if(x >= 0 && x < h&&y >= 0&&y < w && S[Now.first + A[0][i]][Now.second + A[1][i]] != 'X'){
			if(cost[Now.first][Now.second] + 1 < cost[x ][y]){
				 cost[x][y] = cost[Now.first][Now.second] + 1;
				 que.push(make_pair(x, y));
			}
		}
	}
	
	
	//上
	if(Now.first - 1 >= 0 && S[Now.first - 1][Now.second] != 'X'){
		if(cost[Now.first][Now.second] + 1 < cost[Now.first - 1][Now.second]){
			 cost[Now.first - 1][Now.second] = cost[Now.first][Now.second] + 1;
			 que.push(make_pair(Now.first -1, Now.second));
		}
	}
	//下
	if(Now.first + 1 < h && S[Now.first + 1][Now.second] != 'X'){
		if(cost[Now.first][Now.second] + 1 < cost[Now.first + 1][Now.second]){
			 cost[Now.first + 1][Now.second] = cost[Now.first][Now.second] + 1;
			 que.push(make_pair(Now.first + 1, Now.second));
		}
	}
	//hidari
	if(Now.second - 1 >= 0 && S[Now.first][Now.second - 1] != 'X'){
		if(cost[Now.first][Now.second] + 1 < cost[Now.first][Now.second - 1]){
			 cost[Now.first][Now.second - 1] = cost[Now.first][Now.second] + 1;
			 que.push(make_pair(Now.first, Now.second - 1));
		}
	}
	//r
	if(Now.second +1 < w && S[Now.first][Now.second + 1] != 'X'){
		if(cost[Now.first][Now.second] + 1 < cost[Now.first][Now.second + 1]){
			 cost[Now.first][Now.second + 1] = cost[Now.first][Now.second] + 1;
			 que.push(make_pair(Now.first , Now.second + 1));
		}
	}
	
}

int main(){
	//チーズ
	
	cin >> h >> w >> n;

	for(int i=0; i<h; i++){
		cin >> S[i];
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(S[i][j] == 'S'){
				factory[0] = make_pair(i, j);
			}
			else if(S[i][j] != 'X' && S[i][j] != '.'){
				factory[S[i][j]-'0'] = make_pair(i,j);
			}
		}
	}


	int ans = 0;
	for(int i=0; i<n; i++){
		
		for(int j=0; j<h; j++){
			for(int k=0; k<w; k++){
				cost[j][k] = 999999;
			}
		}

		cost[factory[i].first][factory[i].second] = 0;
		que.push(factory[i]);
		while(!que.empty()){
			Solve(que.front());
			que.pop();
		}
		ans += cost[factory[i+1].first][factory[i+1].second];
	}

	cout << ans << endl;


	return 0;	
}
*/

	//宝探し
	/*
	int n,m;
	cin >> n >> m;
	int A[5100][5100];
	//A[0][0] = 0;
	/*
	for(int i=0; i<5000; i++){
		for(int j=0; j<5000; j++){
			//A[i+1][j+1] = A[i+1][j] + A[i][j+1] -A[;
			
		}
	}
	*/
	/*
	int Px[5000],Py[5000];
	for(int i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		
		//A[x][y] = 1;
	}
	
	int B[5100][5100];
	B[0][0] = 0;
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			B[i+1][j+1] = B[i+1][j] + B[i][j+1] - B[i][j] + A[i+1][j+1];
		}
	}

	for(int i=0; i<m; i++){
		int x,y,X,Y;
		cin >> x >> y >> X >> Y;
		cout << B[x][y] - B[X-1][Y-1] << endl;
	}
	*/


	//超観光都市
	/*
		int w,h,n;
		cin >> w >> h >> n;
		int ans = 0;
		int X,Y;
		int x,y;
		cin >> x >> y;
		X = x;
		Y = y;

		for(int i=0; i<n-1; i++){
			cin >> x >> y;
			bool hugou = ((x-X>0&&y-Y>0)||(x-X<0&&y-Y<0));
			if(hugou == 1){
				ans += max(abs(x-X), abs(y-Y));
			}
			else{
				ans += abs(x-X)+abs(y-Y);
			}
			X = x;
			Y = y;
		}
		cout << ans << endl;
*/
	//すごろく
	/*
	while(true){
		int n,m;
		cin >> n >> m;
	if(n==0 && m==0) break;

		int X[1000],Y;
		for(int i=0 ; i<n; i++){
			cin >> X[i];
		}

		int i,a=0;
		for(i=0; i<m; i++){
			cin >> Y;
			a += Y;
			a += X[a];
			if(a+1>=n) break;
		}
		cout << i + 1<< endl;
	}
	*/

	//看板(未完成）
	/*
	int n,Ans;
	string name;
	cin >> n >> name;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int x[100];
        int l=0;
		for(int j=0; j<name.size(); j++){
			for(int k=0; k<s.size(); k++){		
				if(name[j]==s[k]){
					x[l]=k;
					l++;
				}
			}
		}
		int p=x[1]-x[0];
		for(int j=1; j<l+1; j++){
			if(p!=x[j]-x[j-1])
				break;
			

		}
	}
	*/
	//サッカー
	/*
	int n;
	cin >> n;
	int P[100];
	for(int i = 0; i<n; i++){
		P[i]=0;
	}
	
	for(int i=0; i<n*(n-1)/2; i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(c>d)
			P[a-1] += 3; 
		if(c==d){
			P[a-1]++;
			P[b-1]++;
		}
		if(c<d)
			P[b-1] += 3;
	}

	int Q[100];
	for(int i =0; i<n; i++){
		Q[i] = P[i];
	}
	sort(Q, Q+n);
	reverse(Q,Q+n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(P[i]==Q[j]){
				cout << j+1 << endl;
				break;
			}
		}
	}
	*/

	//気象予報士
	/*
		int h,w;
		int x=-1;
		cin >> h >> w;
		
		for(int i=0; i<h; i++){
			for(int j =0; j<w; j++){
				char a;
				cin >> a;
				if(a=='c'){
					cout << 0;
					x = j;
				}
				else if(x != -1){
					cout << j-x;
				}
				else
					cout << -1;
				if(j==w-1)
					break;
				cout << " ";
			}
			cout << endl;
			x = -1;
		}
		*/

	/*
	//数あて
	int n;
	cin >> n;
	int p[200][3];

	for(int i=0;i<n;i++)
	{
		cin >> p[i][0] >> p[i][1] >> p[i][2];
	}

	int _p;
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<n;i++)
		{
			_p = p[i][k];
			for(int j=i+1;j<n;j++)
			{
				if(_p == p[j][k])
				{
					p[i][k] = 0;
					p[j][k] = 0;
				}
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout << p[i][0] + p[i][1] + p[i][2] << endl;
	}
	*/

	/*
	//得点
	int ai,am,as,ae,bi,bm,bs,be;
	cin >> ai >> am >> as >> ae >> bi >> bm >> bs >> be;
	int answer=ai+am+as+ae;
	if(answer < bi+bm+bs+be)
	{
	/	answer=bi+bm+bs+be;
	}
	cout << answer << endl;
	*/
	
	//おつり
/*	int onum;
	while(true){
		int N;
		cin >> N;
		if(N == 0) break;
		onum=0;
		int oturi = 1000-N;
		if(oturi >= 500)
		{
			onum++;
			oturi -= 500;
		}
		while(oturi>=100)
		{
			onum++;
			oturi -= 100;
		}
		if(oturi >= 50)
		{
			onum++;
			oturi -= 50;
		}
		while(oturi>=10)
		{
			onum++;
			oturi -= 10;
		}
		if(oturi >= 5)
		{
			onum++;
			oturi -= 5;
		}
		while(oturi>=1)
		{
			onum++;
			oturi -= 1;
		}
		 cout << onum << endl;
	}
   */

	//レシート
	/*
	while(true){
		int N;
		cin >> N;
		if(N==0) break;
		int a[9];
		for(int i=0;i<9;i++){
			cin >> a[0];
		}

	}
	
	/*
	int N;
	int i = 0;
	while(i<N){
		i++;
	}
	for(int i=0; i<N; i++)
	*/
	/*
	int N;
	int x;
	set<int> a;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> x;
		a.insert(x);
	}
	cout << a.size() << endl;
	*/
	
	//投票
	/*
	int N,M;
	cin >> N >> M;
	int a;
	int A[1000];
	int B[1000];
	int X[1000][2];
	
	for(int i=0; i<N; i++){
		cin >> A[i];
		X[i][0] = i;
		X[i][1] = 0;
	}
	for(int j=0; j<M;j++){
		cin >> B[j];
	}
	for(int j=0; j<M; j++){
		for(int i=0; i<N; i++){
			if(A[i] <= B[j]){
				X[i][1]++;
				break;
			}
		}
	}
	for(int i=1; i<N; i++){
		if(X[i-1][1]<X[i][1])
			X[i-1][0] = X[i][0];
	}
	cout << X[0][0]+1 << endl;
	*/
	/*
	int N,M;
	cin >> N >> M;
	int A[1000];
	int vote[1000];
	for(int i=0; i<N; i++){
		cin >> A[i];
		vote[i] =0;
	}
	int B;
	for(int i=0; i<M; i++){
		cin >> B;
		for(int j=0; j<N; j++){
			if(A[j]<=B){
				vote[j]++;
				break;
			}
		}
	}
	int temps = 0;
	int ans=0;
	for(int i=0; i<N; i++){
		if(vote[i] >= temps){
			temps = vote[i];
			ans = i;
		}
	}
	cout << ans+1 << endl;
	*/

//	return 0;
//}
/*
int max(int i,int j){
	if(i < j) i=j;
	return i;
}
*/
