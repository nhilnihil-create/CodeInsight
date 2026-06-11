// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector< vector<int> >
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

ll power(int m, int n){
    if(n == 0) return 1;
    
    if(n % 2 == 0){
        ll tmp = power(m , n / 2);
        return tmp * tmp % INF;
    }
    return  power(m , n - 1) * m % INF;
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << power(m, n) << endl;
}
