#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h1,m1,h2,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int hour_diff = h2-h1;
    int min_diff = m2-m1;
    int total = hour_diff*60+min_diff-k;
    cout << total <<endl;
    return 0;
    
}

    