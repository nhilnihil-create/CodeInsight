#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007

using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n;
    cin >> n;
    rep1(i,9){
        rep1(j,9){
            int k = i*j;
            if(n==k){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
	return 0;
  
}