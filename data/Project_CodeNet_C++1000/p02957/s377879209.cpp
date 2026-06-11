#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define endl "\n"
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

int main()
{

    long long a, b;
    cin >> a >> b;
    if(a% 2 != b % 2)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << (a + b) / 2 << endl;
    }
    return 0;
}

