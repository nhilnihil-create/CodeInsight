#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> pi;
typedef pair<int,int> vi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(vi c, vi d){
	return c.S < d.S;
}

int main() {
	int A, B, M;
	cin >> A >> B >> M;
	int ref[A], mic[B], mina=10000001, minb=10000001;
	
	REP(i, 0, A){
		cin >> ref[i];
		mina = min(ref[i], mina);
	}
	REP(i, 0, B){
		cin >> mic[i];
		minb = min(mic[i], minb);
	}
	
	int minv = mina + minb;
	int a, b, d;
	REP(i, 0, M){
		cin >> a >> b >> d;
		if(ref[a-1]+mic[b-1]-d < minv) minv = ref[a-1]+mic[b-1]-d;
	}
	cout << minv;
}
