#include<iostream>
#include<functional>
#include<utility>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
const auto MOD = 1000000007;
const int INF = 1e9;
const long long LINF = 1e18;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;




int way[510][510];

int dcnt = 1;//dfsの階層
void fill(VI a, VI b,int dc) {//２つのベクトルを受け取ってレベルdcの道を形成
	int as = a.size();int  bs = b.size();
	rep(i, as)rep(j, bs) {
		int ta = a[i];int tb = b[j];
		if (ta > tb)swap(ta, tb);
		if (way[ta][tb])continue;
		way[ta][tb] = dc;
		//cout << ta << " " << tb << " " << dc << endl;
	}
}

void dfs(VI tn,bool rev,int dcnt) {//rev==1なら席を反転,dcnt dfsの階層
	int ts = tn.size();
	VI ma, usi;
	rep(i, (ts+1) / 2)ma.push_back(tn[i]);
	for (int i = (ts+1)/2; i < ts; i++)
	{
		usi.push_back(tn[i]);
	}
	if (rev)swap(ma, usi);
	fill(ma, usi, dcnt);
	if (tn.size() <= 2)return;
	dfs(ma, 0, dcnt + 1);dfs(usi, 1, dcnt + 1);
}
int main() {
	int n;
	cin >> n;
	VI tn(n);
	for (int i = 0; i < n; i++)
	{
		tn[i] = i;
	}
	dfs(tn,0,1);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			cout << way[i][j] << " ";
		}
		cout << endl;
	}
}