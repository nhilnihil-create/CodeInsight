#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

const long long MOD = 1000000007;

struct WBK {
	int x;
	int y;
	int m;
};

int main(){
	int A,B,M;
	cin >> A >> B >> M;
	vector<int> a(A),b(B);
	WBK m[M];
	
	int a_min=999999;
	for(int i=0;i<A;i++){
		cin >> a[i];
		a_min=min(a_min,a[i]);
	}
	
	int b_min=999999;
	for(int i=0;i<B;i++){
		cin >> b[i];
		b_min=min(b_min,b[i]);
	}
	
	for(int i=0;i<M;i++){
		cin >> m[i].x >> m[i].y >> m[i].m;
	}
	
	//割引を使わない最小額
	int ans_1=a_min+b_min;
	
	//割引を使う最小額
	int ans_2=999999;
	for(int i=0;i<M;i++){
		int now_cost=a[m[i].x-1]+b[m[i].y-1]-m[i].m;
		ans_2=min(ans_2,now_cost);
	}

	//cout << ans_1 << " " << ans_2 << endl;
	cout << min(ans_1,ans_2) << endl;
	return 0;
}
