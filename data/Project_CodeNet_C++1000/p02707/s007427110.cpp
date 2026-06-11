#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
#define rrep(i,n) for(int i = n-1; i >= 0 ; i--)
typedef long long ll;
constexpr auto INFI = 2147483647;
const ll INFL = 9223372036854775807;

int main(){
    int n, tmp;
    cin >> n;
    vector<int> buka(n, 0);
    rep(i,n - 1){
        cin >> tmp;
        tmp--;
        buka[tmp]++;
    }
    rep(i,n) {
        cout << buka[i] << endl;
    }

    return 0;
}