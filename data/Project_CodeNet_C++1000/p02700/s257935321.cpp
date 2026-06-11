// Vivek Rai
// Blazer_007

#include<bits/stdc++.h>
using namespace std;

#define fastio    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl      '\n'

typedef long long int ll;
const int hell = 1e9 + 7 ;

signed main() {

    fastio

    int a , b , c , d;
    cin >> a >> b >> c >> d;


    while(true)
    {
    	c = c - b;
    	if(c <= 0)
    	{
    		cout << "Yes";
    		return 0;
    	}
    	a = a - d;
    	if(a <= 0)
    	{
    		cout << "No";
    		return 0;
    	}
    }

    return 0;
}