#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


#include <bits/stdc++.h>
using namespace std;

int a[12134],b[12345];
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];

    int cc=0,dd=0;
    vector<int> c;
    for (int i=1;i<=n;i++) c.push_back(i);
    int idx=0;
    do {
        idx++;
        bool flag=false;
        for (int i=1;i<=n;i++)
        if (a[i]!=c[i-1]) {
            flag=true;
            break;
        }
        if (!flag) cc=idx;

        flag=false;
        for (int i=1;i<=n;i++)
        if (b[i]!=c[i-1]) {
            flag=true;
            break;
        }
        if (!flag) dd=idx;


    } while (next_permutation(c.begin(), c.end()));

    cout<<abs(cc-dd)<<endl;
    return 0;
}
