#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<pair<int,int>> s(a+b+c);
    for(int i = 0; i < a; i++) {
        cin >> s[i].first;
        s[i].second=0;
    }
    for(int i = 0; i < b; i++) {
        cin >> s[i+a].first;
        s[i+a].second=1;
    }
    for(int i = 0; i < c; i++) {
        cin >> s[i+a+b].first;
        s[i+a+b].second=2;
    }
    sort(s.rbegin(),s.rend());
    int cnt[3]={0,0,0};
    int ans=0;
    int idx=0;
    while((cnt[0]+cnt[1]+cnt[2])<(x+y)) {
        if(cnt[0]==x && s[idx].second==0){
            idx++;
            continue;
        };
        if(cnt[1]==y && s[idx].second==1){
            idx++;
            continue;
        }
        //cout << s[idx].first << "\n";
        ans+=s[idx].first;
        cnt[s[idx].second]++;
        idx++;
    }
    cout << ans << "\n";

    return 0;
}