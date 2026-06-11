
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    int ans = 0;
    rep(i, 0, n) cin >> l[i];
    rep(i, 0, n){
        rep(j, 0, n){
            rep(k, 0, n){
                if(i < j && j < k){
                    if(l[i] == l[j]) continue;
                    if(l[i] == l[k]) continue;
                    if(l[k] == l[j]) continue;
                    if((ll)l[i]+l[j]+l[k] <= max({l[i],l[j],l[k]})*2)continue;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
