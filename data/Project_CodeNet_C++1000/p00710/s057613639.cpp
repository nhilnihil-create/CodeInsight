#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <deque>  
#include <iomanip>

using namespace std;

using ll = long long;
#define INF 1e9
#define MOD 1e9 + 7
#define rep(i, n) for(int i = 0; i < n; i++)
#define loop(i, a, n) for(int i = a; i < n; i++)
#define all(in) in.begin(), in.end()
int main(){
    int n, r;
    while(true){
        cin >> n >> r;
        if(n == 0 && r == 0) break;
        int p[r], c[r];
        rep(i, r) cin >> p[i] >> c[i];
        map<int, int> mp;
        for(int i = 1; i <= n; i++) mp[i] =  n + 1 - i;
        rep(i, r){
            const int P = p[i], C = c[i];
            int A[P + 1] = {0}, B[C + 1] = {0};
            loop(i, 1,  P) A[i] = mp[i];
            loop(i, 1 , C + 1) B[i] = mp[i + P - 1];
            loop(i, 1,  P + C){
                if(i <= C) mp[i] = B[i];
                else mp[i] = A[i - C];
            }
        }
        cout << mp[1] << endl;
    }
    return 0;
}
