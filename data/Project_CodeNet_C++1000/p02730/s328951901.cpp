#include <bits/stdc++.h>
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a) ; i < (int)(b) ; i++)


#define SZ(x) ((int)(x).size())


typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct Vector{
    double x, y;
};

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

bool Kaibun(string s){
    int N = s.length();
    for (int i = 0; i <= (N-1)/2 ; i++)
    {
        if (s[i] != s[N-i-1]) return false;
    }
    return true;

}


int main()
{
    string S, before, after;
    cin >> S;
    int N = S.length();
    if (N % 2 == 0)
        cout << "No" << endl;
    else
    {
        int len = (N-1)/2;
        before = S.substr(0, len);
        after = S.substr(len + 1, len);
        if (Kaibun(S) && Kaibun(before) && Kaibun(after))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
    }
    
    return 0;
}
