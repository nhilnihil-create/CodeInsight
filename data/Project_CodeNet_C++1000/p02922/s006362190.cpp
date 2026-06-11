#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main(){
    int A;
    int B;
    cin >> A >> B;


    int sum = 0;
    int tap = 1;
    while(tap < B){
        sum++;
        tap = tap - 1 + A;
    }

    cout << sum << endl;
}