#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


int main(){
    int N;
    vector<int> P(100010), index(100010);
    
    cin >> N;
    rep(i,N){ cin >> P[i]; P[i]--;}
    rep(i,N) index[P[i]] = i;
    
    Int ans = 0;
    set<int> checked;
    for(int i=N-1; i>=0; i--){
        int id = index[i];
        checked.insert(id);

        auto it1 = checked.find(id);
        int l1 = -1, l2 = -1; // l1: iの1個左, l2: iの2個左
        if(it1 != checked.begin()) l1 = *(--it1);
        if(it1 != checked.begin()) l2 = *(--it1);

        auto it2 = checked.find(id); it2++;
        int r1 = N, r2 = N; // r1: iの1個右, r2: iの2個右
        if(it2 != checked.end()) r1 = *(it2++);
        if(it2 != checked.end()) r2 = *(it2++);

        Int C = (r1-id)*(l1-l2) + (r2-r1)*(id-l1);
        ans += C*(i+1);
    }

    cout << ans << endl;
}