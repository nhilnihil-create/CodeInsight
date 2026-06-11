#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;
    vector<int> a;

    int ans(0),t(1);
    rep(i,n){
        int x;  cin >> x;
        if(x==t){
            t++;
            a.push_back(x);
        }else{
            ans++;
        }
    }

    if(a.size()==0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}