#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    n = n%10;
    string s;
    if(n == 2   || n== 4 || n == 5 || n==7 || n==9)  s = "hon";
    else
        if(n==3) s = "bon";
    else s="pon";
    cout<<s;
    return 0;
}
