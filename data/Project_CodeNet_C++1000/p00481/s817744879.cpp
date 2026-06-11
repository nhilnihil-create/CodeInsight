/*************************

		PCK 2012 t1

************************/

/*#include <stdio.h>
int main(){

	int s;
	int sum = 0;
	int i;

	for ( i = 0; i < 10; i++){
		scanf("%d", &s);
		sum += s;
	}

	printf("%d\n", sum);
}*/

/************************

		PCK 2012 t2

************************/
/*
#include <stdio.h>
int main(){

	int b[3];
	int i;
	for ( i = 0; i < 3; i++){
		scanf("%d", &b[i]);
	}

	if (b[2] == 1)
		printf("Open\n");
	else if (b[0] == 1){
		if (b[1] == 1)
			printf("Open\n");
		else
			printf("Close\n");
	}
	else
		printf("Close\n");
}*/

/****************************

		PCK 2012 t3

****************************/
/*
	#include <stdio.h>
	int main(){

		int n;
		int h[101] = { 0 };
		int i;
		int temp;

		scanf("%d", &n);

		while (n != 0){
			for (i = 0; i < n + 1; i++){
				scanf("%d", &h[i]);
			}

			if ((h[1] - h[0]) + h[1] == h[2]){
				temp = h[1] - h[0];
				for (i = 1; i < n; i++){
					if (h[i] + temp != h[i + 1]){
						printf("%d\n", h[i + 1]);
						break;
					}
				}
			}
			else{
				if ((h[2] - h[1]) + h[2] == h[3])
					printf("%d\n", h[0]);
				else if ((h[1] - h[0]) + h[2] != h[3])
					printf("%d\n", h[2]);
				else
					printf("%d\n", h[1]);
			}

			scanf("%d", &n);
		}
	}
*/

/*************************************

			PCK 2012 t4
						(2??´????±?????????????)
*************************************/
/*
#include <stdio.h>
int main(void)

{

	int n;
	int num[4], l, s, count, i, j, temp;
	scanf("%d", &n);
	while (n != 0000){
		count = 0;
		while (n != 6174){
			num[0] = n / 1000;
			num[1] = (n - num[0] * 1000) / 100;
			num[2] = (n - num[0] * 1000 - num[1] * 100) / 10;
			num[3] = n - num[0] * 1000 - num[1] * 100 - num[2] * 10;
			if (num[0] == num[1] && num[1] == num[2] && num[2] == num[3]) //??¨???????????°???(1111??????7777??????)??????
				break;
			for (i = 0; i<3; i++){
				for (j = i + 1; j<4; j++){
					if (num[i]>num[j]){
						temp = num[i];
						num[i] = num[j];
						num[j] = temp;
					}
				}
			}
			s = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
			l = num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];
			n = l - s;
			count++;
		}
		if (n == 6174 || count>0)
			printf("%d\n", count);
		else
			printf("NA\n");

		scanf("%d", &n);
	}

	return 0;

}*/

/*************************************

			PCK 2012 t5

*************************************/
/*
#include <stdio.h>
#include <algorithm>

int *p, *j;

int bfs(int n,int ){

	return max(n * )
}

int main(){

	int n;

	scanf("%d", &n);
	while (n != 0){

		p = new int[n];
		j = new int[n - 1];

		for (int i = 0; i < n; i++)
			scanf("%d", &p[i]);
		for (int i = 0; i < n - 1; i++)
			scanf("%d", &j[i]);

		scanf("%d", &n);
	}
}*/

//PCK 2013 t4 ????????????????????????
/*/
#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>

int main(){

	int n;
	int hand[100];

	while (cin >> n && n != 0){

		memset(hand, 0, sizeof(hand));
		int field = 0;
		int num = 0;

		for (int i = 0; i < 100; i++){

			char c;
			cin >> c;
			if (c == 'M') hand[num]++;
			else if (c == 'S'){ field += hand[num] + 1; hand[num] = 0; }
			else { hand[num] += field + 1; field = 0; }
			if (num + 1 < n) num++; else num = 0;
		}

		sort(hand, hand + n);

		for (int i = 0; i < n; i++)
			cout << hand[i] << ' ';
		cout << field << endl;
	}
}
*/
/*********************************************************************

	pck 2009 t1			?????\?????§???????°??????????????

*********************************************************************/
/*
#include <iostream>
using namespace std;

int main(){

	int s1, s2;

	while (cin >> s1 >> s2 && s1 != 0 && s2 != 0){

		int sum[5];
		int max;
		int num;
		sum[0] = s1 + s2;
		max = sum[0];
		num = 0;
		for (int i = 1; i < 5; i++){
			cin >> s1 >> s2;
			sum[i] = s1 + s2;
			if (max < sum[i]){
				max = sum[i];
				num = i;
			}
		}

		cout << (char)('A' + num) << ' ' << max << endl;
	}
}*/

/******************************************************************************

	pck 2009 t3			?????§??¬?´???°-??????????????????????????????

*******************************************************************************/
/*
#include <iostream>
using namespace std;
#include <algorithm>

int main(){

	int x, y;
	while (cin >> x >> y && x != 0 && y != 0){

		if (y > x) swap(x, y);
		int count = 0;
		while (y != 0){
			count++;
			x = x % y;
			swap(x, y);
		}

		cout << x << ' ' << count << endl;
	}
}
*/

/************************************************************

		PCK 2013 t3			?????????????????????

************************************************************/
/*
#include <iostream>
using namespace std;

int main(){

	int n;
	while (cin >> n && n != 0){

		int m = n;
		bool flg = false;

		int k;
		for (int i = 0; i < n; i++){
			
			cin >> k;
			if (k >= 2) flg = true;
			if (k == 0) m--;
		}

		if (flg)
			cout << m + 1 << endl;
		else cout << "NA" << endl;
	}
}
*/

/*******************************************

		PCK 2013 t5			??£??¢

********************************************/
/*
#include <iostream>
using namespace std;

int main(){

	int q;
	cin >> q;
	for (int i = 0; i < q; i++){

		int c, a, n;
		int count = 0;

		cin >> c >> a >> n;

		for (; c > 0 && a > 0 && n > 0; count++){
			c--; a--; n--;
		}
		for (; c >= 2 && a > 0; count++){
			c -= 2; a--;
		}
		for (; c >= 3; count++)
			c -= 3;

		cout << count << endl;
	}
}
*/

/*****************************************************************

		PCK 2012 t1			10????§£???????????????????????????

*****************************************************************/
/*
#include <iostream>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);


	int sum = 0;
	int s;
	
	for (int i = 0; i < 10; i++){
	
		cin >> s;
		sum += s;
	}

	cout << sum << "\n";
}
*/
/*
#include <stdio.h>
#include <bitset>
#include <stack>
using namespace std;

class Game
{
public:
	int k;   // ????????????????????????????
	int m;   // ????????§????¶?????????????????????°
	bitset <16> x;   // ??????????????¶???
	Game(int k1, int m1, bitset<16> x1)
	{
		k = k1;
		m = m1;
		x = x1;
	}
};

int main()
{
	int i1, i2, m, m1, n=1, n1, n2, c=1, k, k1, max;
	bitset <16> x, y;

	scanf("%d %d\n", &n, &c);
	while (n > 0) {
		// ??\???
		bitset<16> a[n];
		for (i1 = 0; i1 < n; i1++) {
			for (i2 = 15; i2 >= 0; i2--) {
				scanf("%d", &k);
				a[i1].set(i2, k);
			}
		}
		bitset<16> b[c];
		for (i1 = 0; i1 < c; i1++) {
			for (i2 = 15; i2 >= 0; i2--) {
				scanf("%d", &k);
				b[i1].set(i2, k);
			}
		}
		// ??????
		max = 0;
		stack<Game> st;
		st.push(Game(0, 0, a[0]));
		while (!st.empty()) {
			k = st.top().k;
			m = st.top().m;
			x = st.top().x;
			st.pop();
			for (i1 = 0; i1 < c; i1++) {
				y = x;
				n1 = y.count();
				y ^= b[i1];
				y &= x;
				n2 = y.count();
				m1 = m + n1 - n2;
				if (k == n - 1) {
					if (m1 > max)
						max = m1;
				}
				else {
					k1 = k + 1;
					y |= a[k1];
					st.push(Game(k1, m1, y));
				}
			}
		}
		printf("%d\n", max);
		// ?¬?????????????
		scanf("%d %d\n", &n, &c);
	}

	return 0;
}
*/
/*
#include<iostream>
using namespace std;

#include<algorithm>
#include<cstring>

int main(){

	int n, m, a[101], b[101];
	int point[101];
	memset(point, 0, sizeof(point));

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			cin >> b[j];
			if (b[j] == a[i])point[j]++;
			else point[a[i]]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << point[i] << endl;
}*/
/*						JOI ?°????
#include<iostream>
using namespace std;
#include<stdio.h>
int map[1002][1002];	//???????????????????
int dat[1002][1002];	//??????????????£?????¨?°´????????????????????????????????±
int x[1000001], y[1000001];	//[n]??????????????????????????????????????¨???????????§?¨?
int dx[4] = { 1,0,-1,0 };	//?§??????????
int dy[4] = { 0,1,0,-1 };	//?§??????????
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 0; i < mx + 2; i++) {
		for (int j = 0; j < my + 2; j++) {
			map[i][j] = 1000000000; dat[i][j] = 0;	//?????????
		}
	}
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < my; j++) {
			scanf("%d", &map[i + 1][j + 1]);	//??\???
		}
	}
	for (int i = 1; i <= mx; i++) {
		for (int j = 1; j <= my; j++) {
			x[map[i][j]] = i, y[map[i][j]] = j;	//???????????????????????´???????£?
		}
	}
	int c = 0;	//?°?????????°
	for (int i = 1; i <= mx*my; i++){	//??????¨?

		int r = 0;
		for (int j = 0; j < 4; j++){	//4??????????§????
		
			int a = x[i] + dx[j], b = y[i] + dy[j];	//?§???????
			if (map[a][b] < i)	//??????????????±?????? i ??\?????????
			{
				if (r == 0)r = dat[a][b];	//?§?????????§????????§???????????????
				else if (r != dat[a][b])r = -1;	//??´??????????°????????????£????????????
			}
		}
		if (r == 0)dat[x[i]][y[i]] = i;	//??¨?????????????????????????????°?°´?????????
		else dat[x[i]][y[i]] = r;	//????????¨???????????´????????°?????????
		if (r == -1)c++;	//?°?????????????
	}
	printf("%d\n", c);
}
*/

/*	JOI 2006 ??¬??? t2 ??????????????? */
/*#include <iostream>
using namespace std;

int main() {
	int n, k;
	while (cin >> n >> k && n != 0 && k != 0) {

	}

	return 0;
}*/

/* ?????§?????? */
/*
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main() {
	long long int n;
	long long int k;
	while (cin >> n >> k && n != 0 && k != 0) {
		vector<long long int> v;
		v.push_back(0);

		for (long long int i = 1; i <= n; ++i) {
			long long int m;
			cin >> m;
			v.push_back(m);
			v[i] += v[i - 1];
		}

		long long int sum = 0;
		for (long long int i = 1; i + k <= n; ++i) {
			sum = max(sum, v[i + k] - v[i]);
		}

		cout << sum << endl;
	}
	
	return 0;
}*/

/* JOI 2016 t3 ?????????????????? */
/*
#include<iostream>
using namespace std;

#include<cstring>

int map[102][102] = { 1 };

int main(){
	memset(map, 1, sizeof(map));
	int n, m, d;
	cin >> n >> m >> d;

	for (int i = 0; i < n; ++i) {
		for (int i2 = 0; i2 < m; ++i2) {
			char str;
			cin >> str;
			if (str == '.') { map[i][i2] = 0; }
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int i2 = 0; i2 < m; ++i2) {
			if (map[i][i2] == 0) {

				bool flg = true;
				for (int j = 1; j < d; ++j) {
					if (map[i + j][i2] != 0) {
						flg = false;
						break;
					}
				}
				if (flg) { ++cnt; }

				flg = true;
				for (int j = 1; j < d; ++j) {
					if (map[i][i2 + j] != 0) {
						flg = false;
						break;
					}
				}
				if (flg) { ++cnt; }
			}
		}
	}
	cout << cnt << endl;

	return 0;
}
*/
/*

#include<iostream>
using namespace std;

#include<string>

int dp[101][101] = { 0 };

int main(){
	string s, t;
	cin >> s >> t;

	for (int i = 0; i <= t.size(); ++i) { dp[i][0] = 0; }
	for (int i = 0; i <= s.size(); ++i) { dp[0][i] = 1; }

	for (int i = 1; i <= t.size(); ++i) {
		for (int i2 = 1; i2 <= s.size(); ++i2) {
			if (t[i - 1] == s[i2 - 1]) {
				dp[i][i2] = dp[i - 1][i2 - 1] + dp[i][i2 - 1];
			}
			else dp[i][i2] = dp[i][i2 - 1];
		}
	}	

	cout << dp[t.size()][s.size()] << endl;
	
	return 0;
}
*/
/*
#include<iostream>
using namespace std;

#include<algorithm>

int a[100001];

int main() {
	int n, k;
	while (cin >> n >> k && n != 0 && k != 0) {
		a[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] += a[i - 1];
		}
		int maxi = 0;
		for (int i = k; i <= n; ++i) {
			maxi = max(maxi, a[i] - a[i - k]);
		}

		cout << maxi << endl;
	}

	return 0;
}
*/

/* JOI 2010 ?????´??? */
/*
#include<iostream>
using namespace std;

#include<algorithm>

unsigned long long dp[21][101] = { 0 };

int main() {
	unsigned long long n, num;
	cin >> n;
	for (unsigned long long i = 0; i < n - 1; ++i) {
		cin >> num;
		if (i == 0) {
			++dp[num][i];
		}
		else {
			for (unsigned long long j = 0; j <= 20; ++j) {
				if (dp[j][i - 1] != 0) {
					if (j + num >= 0 && j + num <= 20) {
						dp[j + num][i] += dp[j][i - 1];
					}
					if (j - num >= 0 && j - num <= 20) {
						dp[j - num][i] += dp[j][i - 1];
					}
				}
			}
		}
	}

	cin >> num;
	cout << dp[num][n - 2] << endl;

	return 0;
}
*/

/* JOI 2010 t5 ????????? */

#include<iostream>
using namespace std;

#include<queue>
#include<cstring>

typedef unsigned long long int ullint;

struct Q {
	ullint x;
	ullint y;
};

Q In(ullint x, ullint y) { Q a; a.x = x; a.y = y; return a; }

char map[1002][1002];
ullint num[1003][1003] = { 0 };

ullint xm[] = { 0,0,-1,1 };
ullint ym[] = { -1,1,0,0 };

int main() {
	ullint h, w, n;
	Q st;
	cin >> h >> w >> n;
	for (ullint i = 0; i <= h + 1; ++i) {
		for (ullint i2 = 0; i2 <= w + 1; ++i2) {
			map[i][i2] = 'X';
		}
	}
	for (ullint i = 1; i <= h; ++i) {
		for (ullint i2 = 1; i2 <= w; ++i2) {
			char str;
			cin >> str;
			map[i][i2] = str;
			if (str == 'S') { st.y = i; st.x = i2; }
		}
	}

	queue<Q> que; que.push(st);
	ullint number = 1;
	ullint ans = 0;
	for (number = 1; number <= n; ++number) {
		while (!que.empty()) {
			Q now;
			now = que.front();
			que.pop();
			ullint memo = num[now.y][now.x];
			if (map[now.y][now.x] == '0' + number) {
				ans += memo;
				for (ullint i = 0; i <= h + 1; ++i) {
					for (ullint i2 = 0; i2 <= w + 1; ++i2) {
						num[i][i2] = 0;
					}
				}
				while (!que.empty()) { que.pop(); }
				que.push(In(now.x, now.y));
				break;
			}
			for (ullint i = 0; i < 4; ++i) {
				if (map[now.y + ym[i]][now.x + xm[i]] != 'X') {
					if (num[now.y + ym[i]][now.x + xm[i]] == 0) {
						num[now.y + ym[i]][now.x + xm[i]] = memo + 1;
						que.push(In(now.x + xm[i], now.y + ym[i]));
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}