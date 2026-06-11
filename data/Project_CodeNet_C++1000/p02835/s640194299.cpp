#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int x,int a,int b)
{
    if(x+a+b>=22)
        cout<<"bust";
    else
        cout<<"win";
}
int main()
{
    int x,a,b;
    cin>>a>>b>>x;
    solve(a,b,x);
    return 0;
}