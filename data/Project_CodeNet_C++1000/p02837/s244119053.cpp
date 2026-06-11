#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<vector<int>> xy(N,vector<int>(N,-1));
	for(int i=0; i<N; i++){
		int A;
		cin >> A;
		for(int j=0; j<A; j++){
			int x, y;
			cin >> x >> y;
			xy.at(i).at(x-1)=y;
		}
	}

	int ans=0;
	for(int i=0; i< (1<<15) ; i++){
		bitset<15> bit(i);
		bool flag = true;
		int cnt=0;
		for(int k=0; k<N; k++){
			if(bit.test(k)){
				cnt++;
				for(int j=0; j<N; j++){
					if(xy.at(k).at(j) == -1) continue;
					if(xy.at(k).at(j) != bit.test(j) ){
						flag = false;
					}
				}
			
			}
		}
		if(flag){
			ans = max(ans,cnt);
		}

		if( i==pow(2,N)-1 ) {
			break;
		}
	}

	cout << ans << endl;
	
}
