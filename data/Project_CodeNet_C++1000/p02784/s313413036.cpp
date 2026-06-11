#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n,a;
    cin >> n >> a;

    vector <int> v(a);
    rep(i,a) cin >> v[i];

    int s=0;
    rep(i,a) s+=v[i];


    if (s<n) No();
    else Yes();
    return 0;

}