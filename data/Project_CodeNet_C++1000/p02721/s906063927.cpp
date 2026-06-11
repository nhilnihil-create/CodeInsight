#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main() {
    int n,k,c;
    string s;
    cin >> n >> k >> c >> s;
    vector<ll> mae(1,0),ushiro(1,0);
    int count=0;
    rep(i,n){
        if(s[i]=='o'){
            mae.push_back(i+1);
            count++;
            i+=c;
        }
        if (count==k) break;
    }
    count=0;
    rep(i,n){
        if(s[n-1-i]=='o'){
            ushiro.push_back(n-i);
            count++;
            i+=c;
        }
        if (count==k) break;
    }
    sort(ushiro.begin(),ushiro.end());
    int ans=0;
    rep(i,k){
        if(mae[i+1]==ushiro[i+1]){
            cout << mae[i+1] << endl;
        }
    }
}