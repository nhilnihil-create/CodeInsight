#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int map[1002][1002], was[1002][1002];
int main(void)
{
	int count = 0, H, W, N, i, j;
	char c=0;
	pair<int, int> q,a[10];
	queue<pair<int, int> > que;
	queue<int> quec;
	quec.push(0);
	scanf("%d %d %d", &H, &W, &N);
	for (i = 0; i <= H + 1; i++)
	{
		map[i][0] = -1;
		map[i][W + 1] = -1;
		was[i][0] = -1;					/*?????????????£???????(???)*/
		was[i][W + 1] = -1;
	}
	for (j = 1; j <= W; j++)
	{
		map[0][j] = -1;
		map[H + 1][j] = -1;           /*?????????????£???????????¨????*/
		was[0][j] = -1;
		was[H + 1][j] = -1;
	}
	for (i = 1; i <= H; i++)
	{
		for (j = 1; j <= W; j++)			/*???????????????(??????????????°???????????????????????????????????¨??°??????????????????*/
		{
			cin >> c;
			if (c == 'X')
				map[i][j] = -1;
			if (c == 'S')
			{
				q.first = i;
				q.second = j;
			}
			if (c == '1')
			{
				a[1].first = i;
				a[1].second = j;
			}
			if (c == '2')
			{
				a[2].first = i;
				a[2].second = j;
			}
			if (c == '3')
			{
				a[3].first = i;
				a[3].second = j;
			}
			if (c == '4')
			{
				a[4].first = i;
				a[4].second = j;
			}
			if (c == '5')
			{
				a[5].first = i;
				a[5].second = j;
			}
			if (c == '6')
			{
				a[6].first = i;
				a[6].second = j;
			}
			if (c == '7')
			{
				a[7].first = i;
				a[7].second = j;
			}
			if (c == '8')
			{
				a[8].first = i;
				a[8].second = j;
			}
			if (c == '9')
			{
				a[9].first = i;
				a[9].second = j;
			}
		}
	}
	/*for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}*/
	que.push(q);
	i = 1;
	while (i <= N)
	{
		count = quec.front();
		quec.pop();
		q = que.front();
		que.pop();

		if (q == a[i])
		{

			i++;
			memset(was, 0, sizeof(was));
			while (!que.empty())
				que.pop();
			while (!quec.empty())
				quec.pop();
			quec.push(count);
			que.push(q);
			continue;
		}
		if (map[q.first][q.second + 1] != -1 && was[q.first][q.second + 1] != -1)
		{
			was[q.first][q.second+1] = -1;
			q.second++;
			que.push(q);					/*???????????????*/
			count++;
			quec.push(count);
			count--;
			q.second--;
		}
		if (map[q.first][q.second - 1] != -1 && was[q.first][q.second-1] != -1)
		{
			was[q.first][q.second-1] = -1;
			q.second--;
			que.push(q);
			count++;						/*???????????????*/
			quec.push(count);
			count--;
			q.second++;
		}
		if (map[q.first + 1][q.second] != -1 && was[q.first + 1][q.second] != -1)
		{
			was[q.first + 1][q.second] = -1;
			q.first++;
			que.push(q);
			count++;						/*???????????????*/
			quec.push(count);
			count--;
			q.first--;
		}
		if (map[q.first - 1][q.second] != -1 && was[q.first - 1][q.second] != -1)
		{
			was[q.first-1][q.second] = -1;
			q.first--;
			que.push(q);
			count++;							/*???????????????*/
			quec.push(count);
			count--;
			q.first++;
		}
	}

	printf("%d\n", count);					/*????????£???????????????????¨??????????*/
	return 0;
}