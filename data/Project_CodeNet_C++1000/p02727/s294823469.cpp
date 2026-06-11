#include <bits/stdc++.h>
#define int long long

#define mp make_pair
#define pb push_back
#define mod (int)1e9+7
using namespace std;

signed main(){
    int x,y;
    cin >> x >> y;
    int a,b,c;
    cin >> a >> b >> c;
    int cnt1[a];
    int cnt2[b];
    int cnt3[c];
    for(int i =0;i<a;i++) cin >> cnt1[i];
    for(int i =0;i<b;i++) cin >> cnt2[i];
    for(int i =0;i<c;i++) cin >> cnt3[i];
    multiset<int> s;
    sort(cnt1,cnt1+a);
    sort(cnt2,cnt2+b);
    for(int i = a-1;i >= (a-x);i--) s.insert(cnt1[i]);
    for(int z = b-1;z >= (b-y);z--) s.insert(cnt2[z]);
    for(auto it:cnt3){
        int x = *s.begin();
        if(x < it){
            s.erase(s.begin());
            s.insert(it);
        }
    }
    c = 0;
    for(auto it:s){c += it;}
    cout << c << endl;
}
