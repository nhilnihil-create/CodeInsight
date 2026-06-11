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
    int c=0;
    for (int i=0;i<n-2;i++)
    {
        string s1=s.substr(i,3);
        if (s1=="ABC")
        c++;
    }
    printf("%d\n",c);
    return 0;
}