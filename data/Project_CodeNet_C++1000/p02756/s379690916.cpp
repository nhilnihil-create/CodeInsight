#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#define INF (1e9 + 7)
#define dist(x1, y1, x2, y2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
typedef long long int ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

int main(){
    
	string S;
	cin >> S;
	int Q;
	cin >> Q;
	vi t, f;
	vs c;
	int j, k;
	string l;
	rep(i, Q){
		cin >> j;
		if(j == 1){
			t.push_back(1);
			f.push_back(0);
			c.push_back("0");
		}
		else{
			cin >> k >> l;
			t.push_back(2);
			f.push_back(k);
			c.push_back(l);
		}
	}

	vi acc(Q);
	if(t[Q - 1] == 1){
		acc[Q - 1] = 1;
	}

	for(int i = Q - 2; i >= 0; i--){
		if(t[i] == 1){
			acc[i] = acc[i + 1] + 1;
		}
		else{
			acc[i] = acc[i + 1];
		}
	}
			
	if(acc[0] % 2 == 1){
		reverse(S.begin(), S.end());
	}

		
	rep(i, Q){
		if(t[i] == 2){
			if((f[i] + acc[i]) % 2){
				S = c[i] + S;
			}
			else{
				S += c[i];
			}
		}
	}
	
	cout << S << endl;
		
	return 0;
	
}

