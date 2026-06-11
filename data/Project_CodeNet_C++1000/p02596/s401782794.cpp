#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;


int main(){
    int k;
    cin >> k;
    if(k%2==0){ cout << -1 << endl; return 0;}

    bool flag = false;
    ll ten = 1, tenm = 0;
    for(int i = 1; i <= k; i++){
        tenm = 0;
        ten *= 10;
        ten %= (9 * k);
        tenm += ten - 1;
        tenm %= (9 * k);
        if((7*tenm) % (9*k) == 0){
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout << -1 << endl;

}