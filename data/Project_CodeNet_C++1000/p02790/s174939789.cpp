#include <bits/stdc++.h>

using namespace std;
#define int long long
#define mp make_pair
#define pb push_back


const int inf = 1e18;
const double EPS = 0.00000001;

signed main(){
    int a,b;
    cin >> a >> b;
    string s1,s2;
    s1 = s2 = "";
    for(int i =0;i<a;i++) s1 += (b+'0');
    for(int i =0;i<b;i++) s2 += (a+'0');
    cout << (s1 < s2 ? s1 : s2);
}
