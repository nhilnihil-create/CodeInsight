#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int lcm(int x, int y)
{
    int a;
    a = (x > y) ? x : y; 
    while (true)
    {
        if (a % x == 0 && a % y == 0)
            return a;
        ++a;
    }
}
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a,b;
	cin>>a>>b;
	ll z=lcm(a,b);
	cout<<z;
}