#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n;cin >> n;
    vector<P> a(n);
    for(int i = 0; i < n; i++) {
        int x,y;cin >> x >> y;
        a[i]=P(x+y,x-y);
    } 
    sort(a.begin(),a.end());

    int ans=0,cur=-INF;
    for(int i = 0; i < n; i++) {
        if(cur<=a[i].second){
            ans++;
            cur=a[i].first;
        }
    }
    cout << ans << endl;

    return 0;
}