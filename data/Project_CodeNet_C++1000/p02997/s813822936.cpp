#include<bits/stdc++.h>

#define SORT(v) sort(v.begin(),v.end())
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
#define sll(n,m) scanf("%lld %lld",&n,&m)
#define ss(cad) scanf("%s",cad)
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl; 
#define M 1000000007
#define N_MAX 100010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vp;

int main()
{
	int n, k;
	sii(n, k);
	if(k > ((n-2)*(n-1))/2)
		printf("-1\n");
	else
	{
		vp vec;
		for(int i = 2; i <= n; i++)
			vec.push_back({1, i});
		int curr = ((n-2)*(n-1))/2;
		curr -= k;
		bool sw = 0;
		for(int i = 2; i <= n && sw == 0; i++)
			for(int j = i+1; j <= n && sw == 0; j++)
			{
				if(curr == 0)
				{
					sw = 1;
					break;
				}
				vec.push_back({i, j});
				curr--;
			}
		printf("%d\n",(int)vec.size());
		for(int i = 0; i < vec.size(); i++)
			printf("%d %d\n", vec[i].fst, vec[i].scn);
		printf("\n");
	}
    return 0;
}
