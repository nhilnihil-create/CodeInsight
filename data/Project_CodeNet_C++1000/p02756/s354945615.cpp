#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    ll q;
    cin >> s >> q;
    deque<char> ds(s.size());
    for (ll i = 0; i < s.size(); i++){
        ds[i] = s[i];
    }
    bool rev = true;
 
    for (ll i = 0; i < q; i++){
        ll t;
        cin >> t;
        if (t == 1){
            rev = !rev;
        }
        else{
            ll f;
            char c;
            cin >> f >> c;
            if (f == 1){
                if (rev){
                    ds.push_front(c);
                }
                else{
                    ds.push_back(c);
                }
            }
            else{
                if (rev){
                    ds.push_back(c);
                }
                else{
                    ds.push_front(c);
                }
            }
        }
    }
 
    if (!rev){
        reverse(ds.begin(), ds.end());
    }
 
    for (ll i = 0; i < ds.size(); i++){
        cout << ds[i];        
    }
    cout << endl;
    
}