#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int p[501][501];

void dfs(int id,vector<int>&a){
    int n = a.size();
    if(n<=1)return;
    vector<int>s,t;
    for(int i=0;i<n;i++){
        if(i%2==0){
            s.push_back(a[i]);
        }else{
            t.push_back(a[i]);
        }
    }
    for(auto x:s){
        for(auto y:t){
            p[x][y] = id;
            p[y][x] = id;
        }
    }
    dfs(id+1,s);
    dfs(id+1,t);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        a[i] = i;
    }
    dfs(1,a);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}