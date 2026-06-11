#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define L 300001

bool sort_vect(const vector<int> &v1, const vector<int> &v2)
{
	return v1[0] < v2[0];
}

void update(int *tree, int index, int value)
{
	int i,parent,n;
	n = L;
	i = index + n;
	tree[i] = tree[i] + value;

	while(i>0){
		parent = i/2;
		tree[parent] = max(tree[2*parent], tree[2*parent+1]);
		i = parent;
	}
}

//Segment Tree[1] is maximum
void create(int *tree, int *a)
{
	int i,n;
	n=L;
	for(i=n;i<2*n;i++)
		tree[i] = a[i-n];

	for(i=n-1;i>0;i--)
		tree[i] = max(tree[2*i],tree[2*i+1]);
}

// _j in not inclusive
// For complete tree call (0,n)
ll maximum(int *tree, int _i, int _j)
{
	int n;
	n=L;
	int left,right, maxi = -1;
	left = _i + n;
	right = _j + n;

	while(left < right)
	{
		if(left%2==1){
			maxi = max(maxi, tree[left]);
			left = left + 1;
		}

		if(right%2==1)
		{
			right = right - 1;
			//This will make sure you don't go 'Out of Bound'
			maxi = max(maxi, tree[right]);
		}
		left = left/2;
		right = right/2;
	}
	return maxi;
}

int main()
{
	int H, W, M, a, b, i, j,current;
	ll count,temp;
	cin >> H >> W >> M;

	vector<std::vector<int>> v(M, vector<int>(2));
	for(i=0;i<M;i++){
		cin >> a >> b;
		a--;
		b--;
		v[i][0] = a;
		v[i][1] = b;
	}

	sort(v.begin(), v.end(), sort_vect);

	int *c = new int[L];
	for(i=0;i<L;i++){
		c[i] = 0;
	}

	for(i=0;i<M;i++){
		c[v[i][1]]++;
	}
	int *segTree = new int[2*L];
	create(segTree, c);

	count=0;
	i=0;
	current=v[i][0];
	update(segTree, v[i][1], -1);
	i++;
	j=0;
	while(i<M){
		if(v[i][0]==current){
			update(segTree, v[i][1], -1);
		}
		else{
			temp = maximum(segTree,0,L);
			temp = temp + (i-j);
			if(count<temp)
				count = temp;

			//backprop
			for(j=j;j<i;j++){
				update(segTree, v[j][1], 1);
			}

			j=i;
			current=v[i][0];
			update(segTree, v[i][1], -1);
		}
		i++;
	}

	temp = maximum(segTree,0,L);
	temp = temp + (i-j);
	if(count<temp)
		count = temp ;
	
	cout << count << endl;
	return 0;
}