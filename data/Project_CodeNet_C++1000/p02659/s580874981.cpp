#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define sci(x) int x; scanf("%d", &x);
#define TC(x) sci(x); while(x--)
typedef long long ll;
using namespace std;
int main()
{
    ll a;
    double b;
    cin>>a>>b;
    int d = round(b*100);
    ll c= a*d/100;
    cout<<c<<endl;
    return 0;
}
