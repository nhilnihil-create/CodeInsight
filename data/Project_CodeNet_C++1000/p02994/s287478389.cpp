#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define PRECISION 15
#define DEFAULT_MIN 10000000
#define DEFAULT_MAX -10000000
using namespace std;

int main(){
    int n, l, ans = 0, min = DEFAULT_MIN, tmp = 0;
    cin >> n >> l;
    int val[n];
    for(int i=0; i<n; i++){
        val[i] = i+l;
        ans += i+l;
    }
    for(int i=0; i<n; i++){
        if(abs(val[i]) < min){
            min = abs(val[i]);
            tmp = val[i];
        }
    }
    ans -= tmp;
    cout << ans << endl;
    return 0;
}
