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
    double l;
    cin>>l;
    l=l/3;
    double vol = l*l*l;
    cout<<fixed<<setprecision(12)<<vol<<endl;
    return 0;
}
