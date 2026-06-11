#include <iostream>
#include <map>
#include <ctime>
using namespace std;

int K;
void input()
{
    cin >> K;
}

void solve()
{
    int ten = 10 % K;
    map<int,int> M;
    int before,itr;
    before = itr = 7 % K;
    int cnt = 0;
    while (M[itr] == 0){
        // cout << itr << endl;
        M[itr]++;
        itr = (before * ten + 7) % K;
        before = itr;
        ++cnt;
    }
    if(M[0] != 0) cout << cnt << endl;
    else cout << -1 << endl;
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