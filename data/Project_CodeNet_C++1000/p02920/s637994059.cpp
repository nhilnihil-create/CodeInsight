#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
    int n; cin >> n;
    int nn = n;
    n = (1<<n);
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    vector<int> s;
    s.push_back(a.back());
    a.back() = -1;
    rep(i,nn){
        vector<int> p = s;
        sort(p.begin(),p.end());
        int ai = n-1;
        while (p.size() > 0 && ai >= 0) {
            if(a[ai] == -1){
                --ai;
                continue;
            }
            if(a[ai] < p.back()){
                s.push_back(a[ai]);
                p.pop_back();
                a[ai] = -1;
            }
            --ai;
        }
        if(p.size() > 0){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
