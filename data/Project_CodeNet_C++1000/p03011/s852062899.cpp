/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int P, Q, R;
    cin >> P >> Q >> R;
    int mx = max(P, max(Q, R));
    cout << P + Q + R - mx << endl;
    return 0;
    
}

