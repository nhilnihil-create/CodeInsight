#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, loop = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i) loop *= i;
    vector<int> p(n), q(n), a(n);
    for(int i = 0; i < n; ++i) cin >> p.at(i);
    for(int i = 0; i < n; ++i) cin >> q.at(i);
    for(int i = 0; i < n; ++i) a.at(i) = i + 1;
    int cnt = 0, pa = 0, qb = 0;
    do{
        if(a == p) pa = cnt;
        if(a == q) qb = cnt;
        cnt++;
    }while(next_permutation(a.begin(), a.end()));
    cout << abs(pa - qb) << endl;
    return 0;
}