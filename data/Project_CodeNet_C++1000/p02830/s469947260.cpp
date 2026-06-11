#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    string a,b;
    cin>>a>>b;
    for (int i=0;i<n;i++)
    cout<<a.at(i)<<b.at(i);
    cout<<endl;
    return 0;
}
