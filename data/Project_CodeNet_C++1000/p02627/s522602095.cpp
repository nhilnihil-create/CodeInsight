/*
    Author: MEHXM
*/
#include <bits/stdc++.h>
using namespace std;

#define cp_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long int
#define oo 1000000010
#define MAX 1000000
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define nl "\n"

int main()
{
    cp_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    #endif
    char c;
  	cin >> c;
  	if(c >= 97 && c <= 122)
      cout << "a\n";
  	else
      cout << "A\n";
    return 0;
}