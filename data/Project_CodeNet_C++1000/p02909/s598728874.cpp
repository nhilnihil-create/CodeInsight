#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    string x;
    cin >> x;
    if(x == "Sunny")
        cout << "Cloudy" << endl;
    else if (x == "Cloudy")
        cout << "Rainy" << endl;
    else
        cout << "Sunny" << endl;

	return 0;
}

