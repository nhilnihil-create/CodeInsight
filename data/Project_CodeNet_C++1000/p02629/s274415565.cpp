#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long N;
    cin >> N;
    long long x=1;
    int c=1;
    long long N_=N;
    while (true)
    {
        if (N_-x*26<=0){
            break;
        }
        x*=26;
        c++;
        N_-=x;
    }
    string S;
    N=N_-1;
    while (c>0)
    {
        int a=N%26;
        S=(char)('a'+a)+S;
        N/=26;
        c--;
    }
    cout << S << endl;
}