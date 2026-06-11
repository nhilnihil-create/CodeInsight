#include <bits/stdc++.h>
using namespace std;

string base26 (long long n)
{
    string t = "zabcdefghijklmnopqrstuvwxy" ,res;
    while(n > 0)
    {
        long long x = n%26;
        res = t[x]+res;
        n = ceil((double)n/26)-1;
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;
    cout << base26(n)<<endl;
    return 0;
}