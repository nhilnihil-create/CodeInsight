#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 1e9;
const int MOD = 1000000007;

int main(){
    int n,k;
    cin >> n >> k;
    if(k > ((n-1)*(n-2))/2){
        cout << -1 << endl;
        return 0;
    }
    int m = (n*(n-1))/2 - k;
    vector<P> ans;
    for(int i=1;i<n;i++) ans.push_back(P(0,i));
    int cnt = n-1;
    bool ok = true;
    for(int i=1;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(cnt >= m) {
                ok = false;
                break;
            }
            ans.push_back(P(i,j));
            cnt ++;
        }
        if(!ok) break;
    }

    cout << m << endl;
    for(P p:ans){
        cout << p.first+1 << " " << p.second+1 << endl;
    }
    return 0;
}