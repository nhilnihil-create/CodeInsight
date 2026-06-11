#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, l; cin >> n >> l;
    int sum = 0;
    for(int i = 0; i < n; i++) sum += l + i;

    int tmp = abs(l);
    int eat = 0;
    for(int i = 1; i < n; i++){
        if(abs(l + i) < tmp){
            tmp = abs(l + i);
            eat = i;
        }
    }
    cout << sum - (eat + l) << endl;


    return 0;
}
