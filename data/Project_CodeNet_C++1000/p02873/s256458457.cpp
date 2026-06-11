/* agc 040 a */
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef struct _data {
	int x;
	int y;
} data;

long	cnt_down(long n)
{
	long sum = 0;
	while (n > 0)
	{
		sum += n;
		n--;
	}
	return sum;
}

int  main()
{

	string s;
	cin >> s;
	long sum = 0;
	vector<long> q;
	long cnt ;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
			q.push_back(-1);
		else if (s[i] == '>')
		{
			cnt = 0;
			int j = i;
			while(s[j] && s[j] == '>')
			{
				cnt++;
				j++;
			}
			q.push_back(cnt);
			i = j - 1;
		}
	}
	deque<long> t;
	t.push_back(0);
	long p;
	rep(i, q.size())
	{
		if (q[i] == -1 && (q[i+1] == -1 || q[i + 1] == '\0'))
		{
			p = 1 + t.back();
			sum += p;
			t.push_back(p);
		}
		else if(q[i] == -1 && q[i + 1]  >= 0)
		{
			if (t.back() + 1 >= q[i + 1])
			{
				p = 1 + t.back();
				sum += p;
				t.push_back(p);
				q[i + 1] -= 1;
			}
			else if (t.back() + 1 < q[i + 1])
			{
				p = (q[i+1] - t.back()) + t.back();
				sum += p;
				q[i+1] -= 1;
			}
		} 
		else if (q[i] >= 0)
		{
			sum += cnt_down(q[i]);
			p = 0;
			t.push_back(p);
		}
	}
	cout << sum << endl;
	return (0);
}
