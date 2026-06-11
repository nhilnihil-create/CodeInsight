#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define MAX 505
 
typedef long long ll;

int main(int, char**)
{
    int n, m;
    cin >> n >> m;

    int ofs = 0;
    int fst, snd;
    rep(i,m) {
        fst = i + 1;
        snd = n - i;
        if (fst > n / 4 && n % 2 == 0) snd -= 1;
        cout << fst << " " << snd << endl;
    }

    return 0;
}