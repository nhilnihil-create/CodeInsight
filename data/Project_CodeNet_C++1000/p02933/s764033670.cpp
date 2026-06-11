#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int a;
    string s;
    cin >> a >> s;

    printf("%s\n", a>=3200? s.c_str() : "red");
    return 0;
}
