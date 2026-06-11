#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int k;
    cin >> k;
    if(k<=12){
        cout << k << endl;
        return 0;
    }
    queue<ll> que;
    vector<ll> lun;
    rep(i,12){
        que.push(i+1);
        lun.push_back(i+1);
    }
    que.pop();
    int i=12;
    while(i<k){
        ll  t = que.front();
        que.pop();
        if(t%10==0){
            que.push(t*10);
            que.push(t*10+1);
            lun.push_back(t*10);
            lun.push_back(t*10+1);
            i += 2;
        } else if (t%10==9){
            que.push(t*10+8);
            que.push(t*10+9);
            lun.push_back(t*10+8);
            lun.push_back(t*10+9);
            i += 2;
        } else {
            que.push(t*10+(t%10-1));
            que.push(t*10+(t%10));
            que.push(t*10+(t%10+1));
            lun.push_back(t*10+(t%10-1));
            lun.push_back(t*10+(t%10));
            lun.push_back(t*10+(t%10+1));
            i += 3;
        }
    }
    cout << lun[k-1] << endl;
}