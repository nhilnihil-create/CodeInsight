#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; ll k;
    cin >> n >> k;
    ll k2 = k;
    vector<int> a(n); for(int i=0; i<n; ++i){cin >> a[i]; a[i]--;}
    vector<int> seen(n, 0);
    deque<int> que;
    ll now = 0;
    while(1){
        if(k==0){break;}
        if(seen[now]){break;}
        que.push_back(now);
        seen[now] = 1;
        now = a[now]; 
        k--;
    }

    if(k==0){cout << now + 1 << endl; return 0;}

    while(que[0]!=now){
        que.pop_front();
        k2--;
        if(k2==0){cout << que[0]+1 << endl; return 0;}
    }
    k2 %= que.size();
    cout << que[k2] + 1 << endl;
    return 0;
}