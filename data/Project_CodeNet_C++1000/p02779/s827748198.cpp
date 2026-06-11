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
    vector<bool> table(1000000000);
    int n;
    cin >> n;
    rep(i,n){
        long long a;
        cin >> a;
        if(table[a]){
            cout << "NO" << endl;
            return 0;
        }
        table[a] = true;
    }
    cout << "YES" << endl;
    return 0;
}