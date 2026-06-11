#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n;cin >> n;
    vector<int> a(n);
    bool flag1 = false;
    rep(i,n) {
        char ch;
        cin >> ch;
        a[i] = ch - '1';
        if(a[i]==1) flag1 = true;
    }
    int oddeven = 0;
    int oddeven2 = 0;
    vector<int> bifact(n+1);
    for(int i = 1;i <= n;i++){
        bifact[i] = bifact[i-1];
        int x = i;
        while(x%2==0){
            if(x%2 == 0){
                bifact[i]++;
                x /= 2;
            }
        }
    }

    rep(i,n){
        if(bifact[n-1]-bifact[n-1-i]-bifact[i] > 0) continue;
        oddeven ^= a[i];
        oddeven2 ^= a[i]/2;
    }




    if(oddeven%2) cout << 1 << endl;
    else if(flag1) cout << 0 << endl;
    else cout << 2*(oddeven2%2) << endl;

    
    
}