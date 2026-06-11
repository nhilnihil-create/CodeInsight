#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    string s;
    cin>>s;
    int flag=0;
    for (int i=0;i<s.length();i++)
    {
        if (i%2==1 && s.at(i)=='R')
        flag=1;
        if (i%2==0 && s.at(i)=='L')
        flag=1;
    }
    if (flag==0)
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}