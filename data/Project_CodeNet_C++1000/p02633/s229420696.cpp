#include<bits/stdc++.h>

using namespace std;

void test()
{
    int n;
    cin>>n;

    for(int x=1;true;x++)
    {
        if(x*n%360==0)
        {
            cout<<x;
            return ;
        }
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    test();

    return 0;
}

