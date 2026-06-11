#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a; i<=b; ++i)

/// easy access -------------
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<int,int> pi;
typedef tuple<int, int, int> tp;
typedef vector<vector<int>> vv;
///-------------------------

int main()
{
    Phuong_; /// <3333
    int a[3][3];
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j) {
            cin >> a[i][j];
        }
    }
    bool b[3][3];
    memset(b, false, sizeof(b));
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int u;
        cin >> u;
        for(int i=0;i<3;++i){
            for(int j=0; j<3; ++j) {
                if (a[i][j] ==u){
                    b[i][j]=true;
                }
            }
        }
    }
    bool ans = false;
    for(int i=0; i<3; ++i){
        bool f1= true;
        bool f2= true;
        for(int j=0; j<3; ++j){
            f1 = f1&b[i][j];
            f2 = f2&b[j][i];
        }
        if (f1 || f2) ans = true;
    }
    if (b[0][0] && b[1][1] && b[2][2]) ans=true; else
    if (b[0][2] && b[1][1] && b[2][0]) ans=true;
    if(ans) cout<<"Yes"; else cout << "No";
    return 0;
}
