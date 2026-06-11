#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

struct obs {
    int v;
    int good = 0;
    set<obs*> reachable;
};

int n,m,aa,bb;

obs a[100000];

void solve(){

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> aa;
        a[i].v = aa;
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> aa >> bb;
        aa--;
        bb--;
        a[aa].reachable.insert(&a[bb]);
        a[bb].reachable.insert(&a[aa]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(a[i].good != 0) continue;

        bool flag = true;
        for (auto o : a[i].reachable )
        {
            if(o->v >a[i].v){
                a[i].good = 1;
                o->reachable.erase(&a[i]);
                flag = false;
            }
            else if(o->v  == a[i].v){
                o->good = 1;
                a[i].good = 1;
                flag = false;
            }
            else{
                o->good = 1;
            }
        }
        if(flag) a[i].good = 2;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i].good ==2){
            ans++;
        }
    }
    

    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}