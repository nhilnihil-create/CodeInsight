#include <bits/stdc++.h>
using namespace std;

int H, W, M;

int row[300005], col[300005];
vector<pair<int, int> > squares;

struct st
{
	private:int s, e, maximum;
	private:st *left, *right;
	
	public:st(int _s, int _e)
	{
		s = _s;
		e = _e;
		maximum = 0;
		
		if(s == e)
			return;
			
		int mid = s + (e - s) / 2;
		
		left = new st(s, mid);
		right = new st(mid + 1, e);
	}
	
	public:void update(int pos, int val)
	{
		if(pos < s && pos > e)
			return;
		
		if(s == e)
		{
			maximum = val;
			return;
		}
		
		int mid = s + (e - s) / 2;
		if(pos <= mid)
			left -> update(pos, val);
			
		else
			right -> update(pos, val);
			
		maximum = max(left -> maximum, right -> maximum);
	}
	
	public:int query(int qs, int qe)
	{
		if(qs > qe)
			return 0;
			
		if(qs <= s && e <= qe)
			return maximum;
			
		if(e < qs || qe < s)
			return 0;
			
		return max(left -> query(qs, qe), right -> query(qs, qe));
	}
};

st *root;

int currPtr = 0;
int queryRow(int rowNum)
{
	int maximum = 0, start = 1;
	
	while(currPtr < (int)(squares.size()) )
	{
		if(squares[currPtr].first < rowNum)
		{
			currPtr++;
			continue;
		}
		
		if(squares[currPtr].first > rowNum)
			break;

		maximum = max(maximum, col[squares[currPtr].second] - 1);
		maximum = max(maximum, root -> query(start, squares[currPtr].second - 1)); 
		
		//printf("start = %d, end = %d, ans = %d\n", start, squares[currPtr].second - 1, root -> query(start, squares[currPtr].second - 1) );
		
		start = squares[currPtr].second + 1;
		currPtr++;
	}
	
	//printf("start = %d, W = %d, ans = %d\n", start, W, root -> query(start, W));
	//printf("\n");
	maximum = max(maximum, root -> query(start, W));

	return maximum + row[rowNum];
}

int main()
{
	scanf("%d%d%d", &H, &W, &M);
	for(int i = 1; i <= M; i++)
	{
		int hi, wi;
		scanf("%d%d", &hi, &wi);
		
		row[hi]++;
		col[wi]++;
		squares.push_back(make_pair(hi, wi));
	}
	sort(squares.begin(), squares.end());
	
	root = new st(1, W);
	for(int i = 1; i <= W; i++)
	{
		root -> update(i, col[i]);
		//printf("%d ", root -> query(i, i));
	}
	//printf("\n");
	
	int ans = 0;	
	for(int i = 1; i <= H; i++)
		ans = max(ans, queryRow(i));
	printf("%d", ans);
}
