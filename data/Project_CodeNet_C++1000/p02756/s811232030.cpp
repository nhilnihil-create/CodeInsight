#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

void solve(){
    string s;cin >> s;
    int n = s.size();
    deque<char>d;
    for(int i = 0;i<n;i++) d.push_back(s[i]);
    deque<char>d1;
    for(int i = n-1;i>=0;i--) d1.push_back(s[i]);
    int q;cin >> q;
    int b = 0;
    while(q--){
        int c;cin >> c;
        if(c==2&&b%2==0){
            int a;cin >> a;
            char cc;cin >> cc;
            if(a==1){d.push_front(cc);d1.push_back(cc);}
            else {d.push_back(cc);d1.push_front(cc);}
        }
        else if(c==2){
            int a;cin >> a;
            char cc;cin >> cc;
            if(a==1){d1.push_front(cc);d.push_back(cc);}
            else {d1.push_back(cc);d.push_front(cc);}
        }
        else{
            b++;
        }
    }
   int nn = d.size();
   if(b%2){for(int i = 0;i<nn;i++) cout << d1[i];}
   else for(int i = 0;i<nn;i++) cout << d[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}