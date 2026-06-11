#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++)
        cin >> a[i + 1];
    set<int> s;
    s.insert(1);
    int p = 1;
    while(true){
        if(s.find(a[p]) == s.end()){
            s.insert(a[p]);
            p = a[p];
        }
        else{
            break;
        }
    }
    p = a[p];
    int cnt = 0;
    int q = 1;
    while(true){
        if(a[q] != p){
            cnt ++;
            q = a[q];
        }
        else 
            break;
    }
    cnt ++;
    int l = s.size();
    int ans = 1;
    if(cnt == l){
        k %= l;
        for(int i = 0; i < k; i++)
            ans = a[ans];
    }
    else if(k <= cnt){
        for(int i = 0; i < k; i++)
            ans = a[ans];
        
    }
    else{
        k -= cnt;
        l -= cnt;
        k %= l;
        for(int i = 0; i < cnt; i++)
            ans = a[ans];
        for(int i = 0; i < k; i++)
            ans = a[ans];
    }
    cout << ans << endl;
    return 0;
}