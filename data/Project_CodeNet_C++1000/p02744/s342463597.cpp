#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N;

bool f(string s, int x){
    int n = s.size();
    if(n == N){
        cout << s << endl;
    } else {
        for (int i = 0; i <= x; i++){
            char a = 'a' + i;
            string nex = s + a;
            f(nex, x);
        }
        if(x != 25){
            char b = 'a' + x + 1;
            string nex2 = s + b;
            f(nex2, x+1);
        }
    }

    return 0;
}

int main() {
    cin >> N;

    f("a", 0);

    return 0;
}