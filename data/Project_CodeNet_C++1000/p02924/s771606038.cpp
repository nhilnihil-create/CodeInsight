#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n,temp;
    cin>>n;
    if(n%2==0)
        temp=(n/2)*(n+1);
    else
        temp =( (n+1) / 2) * (n);
    cout<<temp-n<<endl;
    return 0;
    }
