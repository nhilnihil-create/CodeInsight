#include<bits/stdc++.h>
using namespace std;

long long N;

//             p     , pos
vector<pair<long long, long long> >P;

int main(){
	cin >> N;
	for(long long i = 0; i < N; i++){
		long long p;
		cin >> p;
		P.push_back(make_pair(p, i));
	}
	sort(P.begin(), P.end(), greater<pair<long long, long long> >());
	//for(long long i = 0; i < P.size(); i++){
	//	cout << P[i].first << ", " << P[i].second << endl;
	//}

	long long ans = 0;
	set<long long> bigger_pos;
	for(long long i = 0; i < P.size(); i++){
		long long val = P[i].first;
		long long pos = P[i].second;
		auto rit = bigger_pos.lower_bound(pos);
		auto lit = bigger_pos.lower_bound(pos);

		// left2, left1, cur, right1, righ2
		long long left1 = -1;
		long long left2 = -1;
		long long right1 = N;
		long long right2 = N;

		if(rit != bigger_pos.end()){
			right1 = *rit;
			rit++;
			if((rit) != bigger_pos.end()){
				right2 = *(rit);
			}
		}

		if(lit != bigger_pos.begin()){
			lit--;
			left1 = *(lit);
			if((lit) != bigger_pos.begin()){
				lit--;
				left2 = *(lit);
			}
		}


		long long tmp = 0;
		//左の大きいのを取る
		if(left1 != -1){
			//左はleft2 + 1 から left1, 右はpos から right1 - 1まで
			tmp += val * (left1 - (left2 + 1) + 1) * (right1 - 1 - pos + 1);
		}

		//右の大きいのを取る
		if(right1 != N){
			//左はleft1 + 1 から pos, 右はright1 から right2 - 1まで
			tmp += val * (pos - (left1 + 1) + 1) * (right2 - 1 - right1 + 1);
		}
		ans += tmp;

		//cout << "cur " << P[i].first << endl;
		//cout << " add " << tmp << endl;
		//cout << "l1 " << left1 << " l2 " << left2 << " r1 " << right1 << " r2 " << right2 << endl;

		bigger_pos.insert(pos);
	}
	cout << ans << endl;
}