#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
int main(){
 
    int n;
    cin >> n;

    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> q(n);
    rep(i,n) cin >> q[i];
    vector<int> init_perm(n);
    rep(i,n) init_perm[i] = i+1;
    vector<int> current_perm(init_perm);

    int a = 0, b = 0;

    do{
        a++;
        if(current_perm == p) break;
    } while( next_permutation(begin(current_perm), end(current_perm)));

    current_perm = init_perm;
    do{
        b++;
        if(current_perm == q) break;
    } while( next_permutation(begin(current_perm), end(current_perm)));

    cout << abs(b-a) << endl;

    return 0;
 
}