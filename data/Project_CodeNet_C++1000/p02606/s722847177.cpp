#include<iostream>
using namespace std;
typedef long long ll;

void solve()
{
    int l,r,d;
    cin>>l>>r>>d;
    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        if(i%d==0)
            cnt++;
    }
    cout<<cnt<<endl;
}

int main()
{
    solve();
}
