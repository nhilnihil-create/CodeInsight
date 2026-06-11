//自称高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
    int ans = 0;
    int tmp;
    int n;
	pair < int, int > b[50], t;
	vector <pair < int, int >> f;
	cin >> n;
	REP(i, n){
		cin >> b[i].first >> b[i].second;
	}
	REP(i, n){
		for(int j=i+1; j<n; j++){
			t.first = b[i].first - b[j].first;
			t.second = b[i].second - b[j].second;
			if(t.first < 0){
				t.first *= -1;
				t.second *= -1;
			}
			else if(t.first == 0 && t.second < 0){
				t.first *= -1;
				t.second *= -1;
			}
			f.push_back(t);
		}
	}
	sort(f.begin(), f.end());
	int now = 1, ma = 1;
	for(int i = 1; i<f.size(); i++){
		if(f[i-1] == f[i]){
			now++;
		}
		else{
			ma = max(now, ma);
			now = 1;
		}
	}

    if(n>1) cout << n - ma << endl;
	else cout << 1 << endl;
}	