#include <iostream>
using namespace std;

int data[10][10010];
int r, c, i, j, res;
int cnt;
bool flag[15];

#define max(a, b) ((a < b) ? b : a)

void func(int now);

int main(void)
{
	while (cin >> r >> c, r && c){
		cnt = 1;
		for (i = 0; i < 15; i++) flag[i] = false;
		for (i = 0; i < r; i++){
			for (j = 0; j < c; j++){
				scanf("%d", &data[i][j]);
			}
		}
		
		res = 0;
		func(0);
		cout << res << endl;
	}
	
	return 0;
}

void func(int now)
{
	// r > ñ@c > s
	if (now == r){
		int sum = 0;
		for (i = 0; i < c; i++){
			int tmp = 0;
			for (j = 0; j < r; j++){
				if ((!flag[j] && (data[j][i] == 1)) || (flag[j] && (data[j][i] == 0))){
					tmp++;
				}
			}
			// tmp > iñÌ1ÌÐÁ­è©¦µÄ0ÉÈé©¸
			// c - tmp > iñÌ0ÌÐÁ­è©¦µÄ1ÉÈé©¸
			if (tmp < (r - tmp)){
				sum += (r - tmp);
			}
			else {
				sum += tmp;
			}
		}
		res = max(res, sum);
	}
	else if (r < now) return;
	
	flag[now] = true;
	func(now + 1);
	
	flag[now] = false;
	func(now + 1);
	
	return;
}