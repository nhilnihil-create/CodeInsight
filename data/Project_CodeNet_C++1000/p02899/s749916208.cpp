#include <bits/stdc++.h>
using namespace std;
struct dt
{
    int idx, num;
    bool operator<(const dt rhs){
        return num < rhs.num;
    }
}s[100005];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> s[i].num;
        s[i].idx = i;
    }
    sort(s + 1, s + n + 1);
    for(int i = 1; i <= n; ++i){
        cout << s[i].idx << ' ';
    }

}


