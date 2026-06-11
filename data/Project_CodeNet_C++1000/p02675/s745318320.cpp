#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    string s;
    cin >> s;
    char x = *s.rbegin();
    int y = *s.rbegin() - '0';
    int a[] {2, 4, 5, 7, 9};
    int b[] {0, 1, 6, 8};
    if(y == 3)
    {
        cout << "bon" << endl;
    }
    if(find(a, a+5, y) != a+5)
    {
        cout << "hon" << endl;
    }
    if(find(b, b+4, y) != b+4){
        cout << "pon" << endl;
    }
    return 0;
}