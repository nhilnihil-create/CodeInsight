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
    vector<vector<int>> town(n, vector<int>(2, 0));
    rep(i, n) rep(j, 2) scanf("%d", &town[i][j]);

    
    vector<vector<ld>> length(n, vector<ld>(n, 0));
    rep(i, n) rep(j, n) length[i][j] = sqrt(pow(town[i][0]-town[j][0], 2)+pow(town[i][1]-town[j][1], 2));
    
    ld ans = 0;
    vector<int> array(n);
    rep(i, n) array[i] = i;
    
    do{
        rep(i, n-1){
            ans += length[array[i]][array[i+1]];
        }
    }while(next_permutation(all(array)));
    
    rep(i, n) ans /= i+1;
    
    printf("%.10Lf\n", ans);
           
/**/
    return 0;
}