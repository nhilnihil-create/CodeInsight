#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;
 
int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<int, int> > v(n);
    int nowr = 0;
    int noww = 0;
    rep(i, n){
        if(s[i] == 'W') noww++;
        else nowr++;
        v[i] = make_pair(nowr, noww);
    }
    int ans = INF;
    rep(i, n){
        int w = v[i].second;
        int r = v[n-1].first-v[i].first;
        ans = min(max(r, w), ans);
    }
    if(v[n-1].second == n) ans = 0; 
    cout<<ans<<endl;
    return 0;
}