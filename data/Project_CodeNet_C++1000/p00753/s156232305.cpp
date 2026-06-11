#include <bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = n - 1; i >= 0; i--)
#define REP(i,k,n) for(int i = k; i < n; i++)

#define vi vector<int>
#define pb push_back
using namespace std;

int w,h;
const int pmax = 130000 * 2;
int main(){

    int p[pmax];
    rep(i,pmax) p[i] = 1;
    p[0] = p[1] = 0;
    for(int i = 2; i * i < pmax; i++) {
        if(p[i] != 0) {
            for(int j = i * 2; j <= pmax; j += i) {
                p[j] = 0;
            }
        }
    }
    REP(i,1,pmax) p[i] += p[i - 1];
    int n;
    while(cin >> n,n) {
        cout << p[2 * n] - p[n] << endl;
    }
    return 0;

}

