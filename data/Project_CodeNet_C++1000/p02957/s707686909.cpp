#include<iostream>
using namespace std;
int main()
{
        int n,m;  cin>>n>>m;
        if((n+m)&1)  cout<<"IMPOSSIBLE\n";
       else cout<<(n+m)/2;
       return 0;
}
