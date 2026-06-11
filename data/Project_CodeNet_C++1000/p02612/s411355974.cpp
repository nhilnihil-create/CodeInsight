#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    if(test%1000!=0)
        cout<<(test/1000 +1)*1000 - test;
    else
        cout<<0;
    return 0;
}
