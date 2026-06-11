#include <iostream>
#include <ctime>
using namespace std;

int N; string s;
void input()
{
    cin >> N >> s;
}

void solve()
{
    int white=0,red=0;
    for (int i = 0; i < N; ++i){
        if(s[i]=='R') ++red;
        else ++white;
    }
    int cnt = 0;
    for (int i = 0; i < red; ++i){
        if(s[i]=='R') ++cnt;
    }
    cout << red - cnt << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}