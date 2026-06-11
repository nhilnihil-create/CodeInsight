#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string a, b;
    cin >> a >> b;
    int k = 0;
    
    for(int i = 0; i < a.size(); i++){
    	if(a[i] == b[i]) k++;
	}
		cout << k << endl;
		
	
}