#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
const int inf = 1001001000;
const long long int Inf = 1001001001001001000;

void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}


int main()
{
	long long int n, d, a;
	cin >> n >> d >> a;
	vector<pair<long long int, long long int>> enemy(n);
	rep(i,n){
		long long int x, y;
		cin >> x >> y;
		enemy[i] = pair<long long int, long long int>(x, y);
	}
	sort(all(enemy));
	d = d * 2;
	queue<pair<long long int,long long int>> ruiseki_damage;
	long long int ruiseki = 0;
	long long int ans = 0;
	rep(i, n)
	{
		long long int x = enemy[i].first;
		long long int h = enemy[i].second;
		while(!ruiseki_damage.empty() && ruiseki_damage.front().first < x){
			ruiseki -= ruiseki_damage.front().second;
			ruiseki_damage.pop();
		}
		h -= ruiseki;
		if (h > 0){
			long long int t = (h + a - 1) / a;
			ans += t;
			long long int damage = t * a;
			ruiseki += damage;
			ruiseki_damage.push(pair<long long int, long long int>(x + d, damage));
		}
	}
	cout << ans << endl;
	return 0;
}