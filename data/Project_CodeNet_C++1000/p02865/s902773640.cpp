#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll ma=1e6+5;

ll n;

int main()
{
    cin>>n;
    if(n%2==0){
        cout<<n/2-1;
    }
    else{
        cout<<n/2;
    }
    return 0;
}
