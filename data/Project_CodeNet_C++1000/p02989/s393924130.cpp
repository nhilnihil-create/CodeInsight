#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n,k;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a.at(i);
    sort(a.begin(),a.end());
    int ans = 0;


    if(a.at(n/2)==a.at(n/2-1)){
        cout << 0 << endl;
        return 0;
    }else{
        cout << a.at(n/2) - a.at(n/2-1) << endl;
        return 0;
    }

}