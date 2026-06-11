#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// INT VS LL

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (auto c: s){
    	if (c == 'R'){
    		cnt++;
    	}
    	else{
    		cnt = 0;
    	}
    	ans = max(ans, cnt);

    }
    cout << ans << endl;
    return 0;
}