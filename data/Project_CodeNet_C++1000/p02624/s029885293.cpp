#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const int MAX = 1e7+10;
const int  MAX1 = 1e5+10;
const int INF = 1e9+10;
double eps = 1e-6;
int cnt[MAX];



int main(){
    IOS
    int n;
    cin >> n;
    for(int i = 1;i < 1e7+5;i++){
        for(int j = i;j < 1e7+5;j += i){
            ++cnt[j];
        }
    }
    ll sum = 0;
    for(int i = 1;i <= n;i++){
        sum += (ll) i*cnt[i];
    }
    cout << sum << endl;



}


/*


*/
