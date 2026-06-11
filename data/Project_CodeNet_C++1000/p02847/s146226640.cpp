#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n); i++) 
#define dunk(n) cout << n << endl
#define all(a) (a).begin(),(a).end()
typedef pair<int,int> P;
typedef long long ll;

int main() {
    int a = 0;
    string s;
    cin >> s;
    if(s == "SUN") a = 7;
    if(s == "MON") a = 6;
    if(s == "TUE") a = 5;
    if(s == "WED") a = 4;
    if(s == "THU") a = 3;
    if(s == "FRI") a = 2;
    if(s == "SAT") a = 1;
    dunk(a);
    return 0;
}