//=========================================c++
/* ===========================================
// 20.04.03 日立製作所 社会システム事業部 プログラミングコンテスト2020 - A. Hitachi String 
// 
// 
=========================================== */
/* ===========================================

content

=========================================== */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int (i)=1;(i)<=(n);i++)
#define rez(i,n) for(int (i)=0;(i)<(n);i++)
#define ET "\n"
#define CLR(arr) memset(&arr, 0, sizeof(arr))
#define PAIR pair<int, int>
#define UQ unique_ptr
#define MQ make_unique
const ll INF = 1LL << 50;
const int MINI = 10e5+5;

static struct GV{
    string input;
} gv;

void build(){
    cin >> gv.input;
}

void solve(){
    int slen = gv.input.length();
    if ((slen &1) == 1) {
        cout << "No" << ET;
        return;
    }
    
    for (int i = 0; i < slen; i+=2) {
        if (gv.input.substr(i,2) == "hi") {
            
        }
        else {
            cout << "No" << ET;
            return;
        }
    }
    
    cout << "Yes" << ET;
    return;
}

int main(){
    build();
    solve();
    
}