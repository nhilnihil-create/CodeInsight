#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;
const ll INF = 1001001001001001001;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    vector<int> c(n+1);
    for(int i = 1; i <= n; i++) cin >> c[i];

    vector<bool> isvisit(n+1, false);
    ll ans = -INF;
    for(int i = 1; i <= n; i++){
        vector<int> path;
        if(!isvisit[i]){
            int cur = i;
            path.push_back(i);
            isvisit[i] = true;
            while(p[cur] != i){
                path.push_back(p[cur]);
                isvisit[p[cur]] = true;
                cur = p[cur];
            }

            ll cycletotal = 0;
            for(int j = 0; j < path.size(); j++) cycletotal += c[path[j]];
            ll coans = -INF;
            //if(cycletotal < 0){
                for(int start = 0; start < path.size(); start++){
                    ll subtotal = 0;
                    for(int j = 0; j < min((int)path.size(), k); j++){
                        subtotal += c[path[(start+j)%path.size()]];
                        ll cyclepoint = 0;
                        if(cycletotal > 0) cyclepoint = cycletotal * ((k-j-1)/path.size());
                        if(coans < subtotal+cyclepoint) coans = subtotal+cyclepoint;
                    }

                }
            //}else{

            //}
            if(ans < coans) ans = coans;
        }
    }
    cout << ans << endl;
    return 0;
}