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
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;


int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    vector<int> b(1000003);
    rep(i,n){
        if(b[a[i]] <= 1){
            for(int j = 1; j <= 1000003/a[i]; j++){
                b[a[i]*j]++;
            }
        }
    }
    int cnt = 0;
    rep(i,n){
        if(b[a[i]] == 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

