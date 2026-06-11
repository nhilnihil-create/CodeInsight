/*
          ,     \    /      ,
         / \    )\__/(     / \
        /   \  (_\  /_)   /   \
   ____/_____\__\@  @/___/_____\____
  |             |\../|              |
  |              \VV/               |
  |        ------hoi-------         |
  |_________________________________|
   |    /\ /      \\       \ /\    |
   |  /   V        ))       V   \  |
   |/     `       //        '     \|
   `              V                '
*/

#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define Speedforce boost();
#define fop(s1, s2) freopen(s1, "r", stdin);freopen(s2, "w", stdout);

using namespace std;

void boost(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 1e6;
const ll inf = 1e9 + 7;
const ld PI = acos(-1);

ll bin_pow(ll x, ll y){
    ll res = 1, base = x;
    while(y){
        if(y & 1){
            res *= base;
            res %= inf;
        }
        base *= base;
        base %= inf;
        y /= 2;
    }
    return res;
}

string s;

int main(){
    Speedforce
    //fop("", "")
    cin >> s;
    for(int i = 0;i < s.size();i ++){
        if((i & 1) && s[i] != 'i'){
            cout << "No";
            return 0;
        }
        if(!(i & 1) && s[i] != 'h'){
            cout << "No";
            return 0;
        }
    }
    if(s.size() & 1){
        cout << "No";
        return 0;
    }
    cout << "Yes";
}
