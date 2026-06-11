#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define reps(i, m, n) for (int i = m; i < n; i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    vector<int> q(n);
    vector<int> array(n);
    rep(i, n) scanf("%d", &p[i]);
    rep(i, n) scanf("%d", &q[i]);
    rep(i, n) array[i] = i+1;
    
    int judge1, judge2;
    int index = 0;
    do{
        if (p == array) judge1 = index;
        if (q == array) judge2 = index;
        index++;
    } while(next_permutation(all(array)));
    
    int ans = abs(judge1-judge2);
    printf("%d\n", ans);
    
    return 0;
}