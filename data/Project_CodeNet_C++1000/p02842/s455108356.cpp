#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>


using namespace std;

const int MAX	= 1e5 + 5;
const int LIM	= 3e5 + 5;
const int MOD	= 1e9 + 7;
const long double  EPS	= 1e-10;
const double PI = acos(-1.0);

typedef long long LL; 
typedef long double LD;


#define uint64 unsigned long long
#define int64 long long


#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

////////////////////////////////////////////////////////////////

int main()
{
    double  N;
    cin >> N;

    int ans = N / 1.08;

    if (ceil(N/1.08) < ceil((N+1) / 1.08)) {
            cout << ceil(N/1.08) << "\n";
            }
    else {
        	cout << ":(" << "\n";
        }
        return 0;
}


