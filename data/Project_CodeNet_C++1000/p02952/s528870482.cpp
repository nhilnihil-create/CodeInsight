#include <bits/stdc++.h>
using namespace std;

int count(int x){
    if (x<10) return 1;
    return count(x/10)+1;
}

int main() {
	int N;
	cin >> N;
	int ans=0;
	for (int i=1; i<=N; i++){
	    if (count(i)%2==1) ans++;
	}
	cout << ans << endl;
}