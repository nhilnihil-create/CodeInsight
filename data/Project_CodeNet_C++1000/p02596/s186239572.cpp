#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input01.txt", "r", stdin);
    // freopen("output01.txt", "w", stdout);
    long long int k,n=7,t=1;
    unordered_set<int> s;
    cin>>k;
    n%=k;
    while(s.find(n)==s.end())
    {
        s.insert(n);
        if(n%k==0)
        {
            cout<<t;
            return 0;
        }
        n=(n*10+7)%k;
        t++;
    }
    cout<<"-1";
    return 0;
}