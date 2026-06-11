#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int k;
    cin >> k;
    vector<int> table(k);
    rep(i,k) table[i] = -1;
    int next = 7 % k;
    int cnt = 1;
    while(table[next] == -1){
        if(next == 0){
            cout << cnt << endl;
            return 0;
        }
        table[next] = cnt;
        cnt++;
        next = (next * 10 + 7) % k;

    }
    cout << "-1" << endl;
}