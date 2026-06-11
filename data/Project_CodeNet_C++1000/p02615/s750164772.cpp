#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n; cin >> n;
    vector<int> a(n);
    priority_queue<int> que;
    for(int i=0; i<n; ++i){cin >> a[i]; que.push(a[i]);}
    ll res = 0;
    ll cnt = n-1;
    for(int i=0; i<n-1; ++i){
        if(i==0){res += que.top(); que.pop(); cnt--;}
        else{
            res += que.top(); cnt--;
            if(cnt>0){res += que.top(); cnt--;}
            que.pop();
        }
        if(cnt==0){break;}
    }
    cout << res << endl;
}