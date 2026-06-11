#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int idx=1;
    for(int i=1800;i>=400;i-=200)
    {
        if(n>=i)
        {
            cout<<idx<<endl;
            return 0;
        }
        idx++;
    }
}
