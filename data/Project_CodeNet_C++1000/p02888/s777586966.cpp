#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
vector<long long> L;

int main(){
	cin >> N;
	rep(i, N) {
		long long tmp;
		cin >> tmp;
		L.push_back(tmp);
	}
	sort(L.begin(), L.end());

	//cout << "item " << endl;
	//for(auto item: L) {
	//	cout << item << endl;
	//}

	long long ans = 0;

	for(long long i = 0; i < N; i++) {
		for(long long j = i + 1; j < N; j++) {
			long long a = L[i];
			long long b = L[j];


			long long start = j;
			long long end = N;

			//minicを探す
			while(start + 1 < end) {
				long long mid = (start + end)/2;
				if(max(a-b, b-a) >= L[mid]) {
					start = mid;
				} else {
					end = mid;
				}
			}
			long long c_minidx = end;


			start = j;
			end = N;

			//maxcを探す
			while(start + 1 < end) {
				long long mid = (start + end)/2;
				if(a+b <= L[mid]) {
					end = mid;
				} else {
					start = mid;
				}
			}
			long long c_maxidx = start;

			//cout << "i = " << i << " j = " << j << " minidx " << c_minidx << " maxidx " << c_maxidx << endl;

			ans += (c_maxidx - c_minidx + 1);


		}
	}
	cout << ans << endl;






}
