#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    s=s.append("#");
    int c=0;
    for (int i=1;i<=n;i++)
    {
        if (s.at(i)!=s.at(i-1))
        c++;
    }
    printf("%d\n",c);
    return 0;
}