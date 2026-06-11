#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int m,d;
    cin >> m >> d;
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int id=1;id<=d;id++){
            int d1 = id%10;
            int d10 = id/10;
            if( (d1 >= 2 && d10 >= 2) && (i == d1*d10))ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}

/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/