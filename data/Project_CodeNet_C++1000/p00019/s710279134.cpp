#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;


int kaizyou(int n,ll sum);

int n;
ll ans=1;

int main(){
	while(cin >> n){
		ans = 1;
		kaizyou(n,ans);
		cout << ans << endl;
	}
}

int kaizyou(int n,ll sum){
	if(n > 1){
		ans = sum * n;
		kaizyou(n - 1,ans);
	}

}