#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int k;
	cin >> k;

	if(k%2==0 || k%5==0){
		cout << "-1" << endl;
		return 0;
	}
	
	int cnt = 7;
	for(int i=0;i<k;i++){
		if(cnt%k==0){
			cout << i+1 << endl;
			return 0;
		}
		cnt *= 10;
		cnt += 7;
		cnt = cnt%k;
	}

	cout << "-1" << endl;
	return 0;
}
