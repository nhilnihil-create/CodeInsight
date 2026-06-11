#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int n, m;
    cin >> n >> m;
    vector<int> vote(n);
    int all = 0;
    rep(i, n){
        cin >> vote.at(i);
        all += vote.at(i);
    }

    int can_select=0;
    rep(i, n){
        if(vote.at(i) >= 1.0/(4.0*m) * all){
            can_select++;
        }
    }
    if(can_select >= m) cout << "Yes\n";
    else cout << "No\n";


    return 0;
}