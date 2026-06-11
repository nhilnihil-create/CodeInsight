//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i,odd;
    cin>>n;
    odd=n/2;
    if(n%2) odd++;
    cout.setf(ios::fixed);
    cout.precision(7);
    cout<<(odd*1.0)/n<<endl;

    return 0;
}



