#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

#define ll long long
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){ return (a % b)? gcd(b, a%b) : b; }
template<typename T> T lcm(T a, T b){ return a * b / gcd(a, b); }

int n, m, q;
vector<int> a, b, c, d;

int dfs(vector<int> &A){
    int res = 0;
    if(A.size() == n){
        int ans = 0;
        REP(i,q){
            if(A[b[i]-1]-A[a[i]-1] == c[i]){
                ans += d[i];
            }
        }
        
        return ans;
    }

    int num = A.empty()? 1: A.back();
    for(int i = num; i <= m; i++){
        A.push_back(i);
        res = max(res, dfs(A));
        A.pop_back();
    }
    return res;
}

int main(void){
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    REP(i,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> A;
    cout << dfs(A) << endl; 
    
    return 0;
}