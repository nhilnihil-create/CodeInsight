#include <bits/stdc++.h>
using namespace std;
const int mod= 1e9+7;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " is " << x << endl;
int main()
{
    int n,x;
    cin>>n;

    bool bo=1;
    for (int i=0; i<n; ++i)
    {
        cin>>x;
        if (x%2==0)
        {
            if (x%3!=0 && x%5!=0)
                bo=0;
        }
    }
    bo?cout<<"APPROVED":cout<<"DENIED";



}
