#include<bits/stdc++.h>
typedef long long ll;
const int N= 1e5+5;
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
        cout<<"0";
    else cout<<n-k;
    return 0;
}
