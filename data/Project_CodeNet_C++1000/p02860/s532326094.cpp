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
    if (n%2==1)
    printf("No\n");
    else
    {
        int c=0;
        for (int i=0;i<n/2;i++)
        {
            if (s.at(i)==s.at(i+n/2))
            c++;
        }
        if (c==n/2)
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}