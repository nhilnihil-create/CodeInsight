#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
// scanf("%d %d %d %d",&w,&b,&d,&s); %lld
// printf("%d\n" ,points);
// const double PI=acos(-1);

int main()
{
	int n; cin >> n;
	ll ans = 0;
	vector<int> l(n);
	for(int i = 0; i<n; i++)
		cin >> l[i];
	sort(l.begin(), l.end());
	
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			int aux, x;
			aux = l[i] + l[j];
			//x = lower_bound(l.begin(), l.end(), aux);
			x = (lower_bound(l.begin(), l.end(), aux) - l.begin())-1;
			//cout << x << " " << j << endl;
			ans += (x - j);
			//cout << ans << endl;
		}
	}
	cout << ans << endl;
}