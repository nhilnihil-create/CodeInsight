#include <bits/stdc++.h>
#define ll long long
#define Arman_Sykot ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
using namespace std;

int main()
{
/*********************/
// Author:
        Arman_Sykot;
/*********************/
    
    int x;
    cin >> x;
    int res = x / 500 * 1000;
    
    x %= 500;
    res += x / 5 * 5;
    
    cout << res << "\n";
    
    return 0;
}
