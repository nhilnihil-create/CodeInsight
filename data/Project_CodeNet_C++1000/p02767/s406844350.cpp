#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
        int n, ans = 50000000;
        cin >> n;
        vector<int> x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int p = 1; p <= 100; p++){
                int temp = 0;
                for(int elem : x){
                        temp += (p - elem) * (p - elem);
                }
                ans = min(ans, temp);
        }
        cout << ans << endl;
	return 0;
}
