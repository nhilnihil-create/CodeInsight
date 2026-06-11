#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    pair<string, int> p[n];
    for(int i = 0; i < n; i++) {
        string music; int time; cin >> music >> time;
        p[i] = make_pair(music, time);
    }
    string t; cin >> t;
    int ans = 0;
    bool sleep = false;
    for(int i = 0; i < n; i++) {
        if(p[i].first == t){
            sleep = true;
            continue;
        }
        if(sleep){
            ans += p[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}