#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,x,y,z,cnt=0;
    cin>>n;
    vector <int> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i+=2)cnt+=(v[i]%2!=0);
    cout<<cnt<<endl;
    return 0;
}