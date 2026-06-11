#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, cnt1, cnt2;
    cin>>x;
    cnt1=x/500;
    cnt2=(x%500)/5;
    int a=cnt1*1000+cnt2*5;
    cout<<a;

}


