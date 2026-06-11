#include <iostream>
#include <bits/stdc++.h>
#define lli unsigned long long int
using namespace std;
#define S second
#define F first
#define pb push_back
#define M1 1000000007
#define M2 998244353
#define pint pair<int,int>
#define setit set<int>::iterator seti
#define mapit map<int,int> ::iterator mapi
#define MP make_pair
#define MT make_tuple
#define PI 3.14159265358979323846
// map      iterator->first  iterator.first
// map      mp[key]=value
// set      *s.begin()
// vector   v[j]=value
// pair     p.first p.second
// vector of pairs v[j].first v[j].second
// tuple    get<index>(tuple_name)
// vector of tuples get<index>(v[j])  sort(v.begin(),v.end())
//priority queue .top() .pop() .push()
// __gcd(x,y)
#define mini(x,y) (y + ((x - y) & ((x - y) >>(sizeof(int) * CHAR_BIT - 1))))
#define maxi(x,y) (x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))))
#define fr(j,a,b) for(j=a;j<b;j++)

int power(int x, unsigned int y, int p)
{   int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {   if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main()
{/*
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
*/
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli t, n, g, b, i, x, j;
    cin >> n;
    n--;
    n = (n * (n + 1)) / 2;
    cout << n;
}

