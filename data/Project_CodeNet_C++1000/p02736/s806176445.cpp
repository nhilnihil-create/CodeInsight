#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1e12;
const int MOD = 1000000007;


int main() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        rep(i,n){
                a[i] = s[i] - '0' - 1;
        }
        int one = 0;
        bool in_one = false;
        rep(i,n){
                if((a[i] % 2 == 1) && (((n-1) & i) == i)) one ++;
                if(a[i] == 1) in_one = true;
        }
        one %= 2;
        if(one == 1) {cout << 1 << endl; return 0;}
        if(in_one) {cout << 0 << endl; return 0;}

        int two = 0;
        rep(i,n){
                if((a[i] == 2) && (((n-1) & i) == i)) two ++;
        }
        two %= 2;
        if(two == 1) cout << 2 << endl;
        else cout << 0 << endl;


        return 0;
}