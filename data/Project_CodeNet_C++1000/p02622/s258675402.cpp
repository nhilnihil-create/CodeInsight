#include <iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define rpt(i,x) for (int i = 0; i < x; i++)
#define fti(i,f,t) for (int i = f; i <= t; i++)
#define fte(i,f,t) for (int i = f; i < t; i++)
#define rptws(i,x,s) for (int i = 0; i < x; i += s)
#define llrpt(i,x) for (long long i = 0; i < x; i++)
#define llfti(i,f,t) for (long long i = f; i <= t; i++)
#define llfte(i,f,t) for (long long i = f; i < t; i++)


int main () {
    string s1,s2;

    getline(cin, s1);
    getline(cin, s2);

    int rst = 0;
    rpt (i, s1.size()) {
        if (s1[i] != s2[i]) rst++;
    }

    cout<<rst;
    return 0;
}