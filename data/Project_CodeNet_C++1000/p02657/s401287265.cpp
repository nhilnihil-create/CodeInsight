#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const double pi = 3.14159265358979323846;

#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

void rw()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
    speed;
    //rw();

    ll q,p;
    cin>>q>>p;
  	cout<<q*p;
    return 0;
}
