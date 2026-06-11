#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

char num_to_char(int n) {
    if (n == 1) return 'a';
    else if (n == 2) return 'b';
    else if (n == 3) return 'c';
    else if (n == 4) return 'd';
    else if (n == 5) return 'e';
    else if (n == 6) return 'f';
    else if (n == 7) return 'g';
    else if (n == 8) return 'h';
    else if (n == 9) return 'i';
    else if (n == 10) return 'j';
    else return 'z';
}

vector<string> v;
int N;

void dfs(string s, int i) {
    if (s.size() == N) v.push_back(s);
    else {
        rep1(j,i) {
            dfs(s + num_to_char(j), i);
        }
        dfs(s + num_to_char(i+1), i+1);
    }
}

int main(){ 
    cin >> N;

    dfs("a",1);

    rep(i,v.size()) cout << v[i] << endl;
}
