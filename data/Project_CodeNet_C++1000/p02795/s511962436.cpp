#include <bits/stdc++.h>
using namespace std;
int main()
{
    float h,w,n;
    cin>>h>>w>>n;
    cout<<ceil(n/max(h,w))<<"\n";
}