#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,z;
    cin>>x>>y>>z;
    if((x+y+z)>=22)
    cout<<"bust"<<endl;
    else
    cout<<"win";
}