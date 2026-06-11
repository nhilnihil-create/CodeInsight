#include <bits/stdc++.h>

 
using namespace std;
 
typedef long long ll;
#define pi   acos(-1) 
#define endl "\n"
const int mod = 1000000007; 

int main()
{
	int a;
	cin >> a ;
	if ( a % 2 == 0){
		cout << a / 2  << endl;
	}
	else 
		cout << (a /2) + 1 << endl;
		
    return 0;
}