#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
	int n;
    cin >> n;
    int a[n];
    ll sum = 0;
    REP(i,n){
        cin >> a[i];
        sum += abs(a[i]);
    }
    sort(a, a + n);
    int mn = a[0], mx = a[n - 1];
    if(a[0] * a[n - 1] <= 0){
        cout << sum << endl;
    }else if(mn > 0){
        cout << sum - 2 * mn << endl;
    }else{
        cout << sum + 2 * mx << endl;
    }
    for(int i = 1; i < n - 1; i++){
        if(a[i] >= 0){
            cout << mn << " " << a[i] << endl;
            mn -= a[i];
        }else{
            cout << mx << " " << a[i] << endl;
            mx -= a[i];
        }
    }
    cout << mx << " " << mn << endl;
}