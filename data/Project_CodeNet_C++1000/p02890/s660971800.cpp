#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        int x;
        cin >> x;
        a[x-1]++;
    }
    sort(a.begin(), a.end());
    vector<int> s(n+1);
    rep(i, n) s[i+1] = s[i] + a[i];
    for (int k = 1; k <= n; k++){
        int l = 0, r = n / k + 1; // l:OK, r:NG
        while(l + 1 < r){
            int c = (l + r) / 2;
            bool ok = [&](int c){
                int i = lower_bound(a.begin(), a.end(), c) - a.begin();
                int sum = c * (n - i) + s[i];
                return (sum >= c * k);
            }(c);
            if(ok) l = c; else r = c;
        }
        printf("%d\n", l);
    }
}