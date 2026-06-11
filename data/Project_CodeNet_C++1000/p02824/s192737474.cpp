#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 110000;

int a[maxn], b[maxn];

bool check(int n,ll m,ll v,int p,int id){
    ll tot = m * (v - 1);
    for (int i = 1;i <= n;i++) a[i] = b[i];
    a[id] += m;
    int target = a[id];
    //If some problem has even higher rating already,add them.
    for (int i = n;i >= 1;i--){
        if (i == id) continue;
        if (tot == 0) break;
        if (a[i] > a[id]){
            tot -= m;
            a[i] += m;
            
        }
    }
    //Start from lowest and help them, but never exceed a[id]
    for (int i = n;i >= 1;i--){
        if (i == id) continue;
        if (tot == 0) break;
        if (a[i] < a[id]){
            int delta = a[id] - a[i];
            tot -= min(delta,(int)min(tot,m));
            a[i] += min(delta,(int)min(tot,m));
        }
    }
    //Finally, when there are still leftovers, all that are originally greater has now been added into full; all that are less are now the same; try to make fewest exceed our target
    //Check whether left is ordered from left to right

    if (tot > 0){
        for (int i = n-1;i >= 1;i--){
            int left_cur = m - (a[i] - b[i]);
            int left_nxt = m - (a[i+1] - b[i+1]);
            if (left_cur > left_nxt && left_nxt != 0){
                cout << "error\n";
            }
        }
        for (int i = n;i >= 1;i--){
            if (i != id){
                int left = m - (a[i] - b[i]);
                a[i] += min((ll)left, tot);
                tot -= min((ll)left, tot);
            }
        }
    }
    sort(a+1,a+n+1,std::greater<int>());
    if (target >= a[p]) return true;
    return false;
    //Now sort again
}
int main(int argc, const char * argv[]) {
    int n, p;
    ll m, v;
    cin >> n >> m >> v >> p;
    for (int i = 1;i <= n;i++){
        cin >> b[i];
    }
    sort(b+1,b+n+1);
    int lower = 1;
    int upper = n;
    int ans = n;
    while (lower <= upper){
        int mid = (lower + upper) / 2;
        if (check(n,m,v,p,mid)){
            ans = mid;
            upper = mid - 1;
        }
        else{
            lower = mid + 1;
        }
    }
    cout << (n - ans + 1) << endl;
    return 0;
}
