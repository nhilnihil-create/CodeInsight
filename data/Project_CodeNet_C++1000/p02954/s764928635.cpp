#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n=s.size();
    int ans[n]={};
    vector<int> sw;

    sw.emplace_back(-1);
    for(int i = 0; i < n-1; i++) {
        if(s[i]!=s[i+1]) sw.emplace_back(i);
    }
    sw.emplace_back(n-1);

//    for(int i = 0; i < sw.size(); i++) {
//        cout << sw[i] << " ";
//    }
//    cout << "\n";

    for(int i = 1; i < sw.size(); i+=2) {
        int left=sw[i]-sw[i-1];
        int right=sw[i+1]-sw[i];
        ans[sw[i]]  = (left+1)/2+right/2;
        ans[sw[i]+1]= left/2+(right+1)/2;
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}