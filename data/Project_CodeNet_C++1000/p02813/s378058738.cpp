#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n,count=0, ans=0;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];

    vector<int> list(n);
    rep(i,n) list[i] = i+1;
    int a = 0, b = 0, equal_count = 0;
    do {
        count++;
        if (p == list || q == list ) {
            equal_count++;
            if (p == list && q == list) {
                ans = 0;
            }
            else {
                if (equal_count==1) {
                    a = count;
                } else {
                    b = count;
                }
            }
            
        }
        
    } while(next_permutation(list.begin(), list.end()));
    cout << b-a << endl;
    return 0;
}