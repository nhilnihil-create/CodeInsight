#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int x;
    cin>>x;
    long long int y=x;
    long long int a=360;
    long long int rotate=0;
    while(x%a!=0)
    {
        x+=y;
        rotate++;
    }
    cout<<rotate+1<<"\n";
}