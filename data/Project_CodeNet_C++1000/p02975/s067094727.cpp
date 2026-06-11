#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,m,n) for(ll i = (m); i < (n); i++)
#define all(v) v.begin(), v.end()
#define print(x) cout << (x) << endl
//宣言
int N,cnt1,cnt2,cnt3;
ll x,a1,a2,a3;
bool valid1 = true,valid2 = false;

void solve(){
    if(valid1 && valid2) print("Yes");
    else print("No");
}

int main() {
    a1 = a2 = a3 = -1;
    cnt1 = cnt2 = cnt3 = 0;
    cin >> N;
    rep(i,N){
        cin >> x;
        if(x == a1) cnt1++;
        else if(x == a2) cnt2++;
        else if(x == a3) cnt3++;
        else if(a1 == -1){a1 = x;cnt1++;}
        else if(a2 == -1){a2 = x;cnt2++;}
        else if(a3 == -1){a3 = x;cnt3++;}
        else{valid1 = false;break;}
    }
    if(a2 == -1){
        if((a1^a1) == a1) valid2 = true;
    }else if(a3 == -1){
        if(a1 == 0 && cnt1*2 == cnt2) valid2 = true;
        if(a2 == 0 && cnt2*2 == cnt1) valid2 = true;
    }else if(cnt1 == cnt2 && cnt2 == cnt3){
        if((a1^a2) == a3) valid2 = true;
    }

    solve();
    return 0;
}
