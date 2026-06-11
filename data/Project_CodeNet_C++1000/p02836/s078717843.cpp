#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    string s;
    cin>>s;
    int c=0;
    for (int i=0;i<s.length()/2;i++)
    {
        if (s.at(i)!=s.at(s.length()-1-i))
        c++;
    }
    printf("%d\n",c);
    return 0;
}