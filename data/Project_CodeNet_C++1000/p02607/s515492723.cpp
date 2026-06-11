/*
*         ****FOX****
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>
//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#include <utility>
#include <list>
#include <cstdio>
#include<forward_list>
#include<algorithm>
#include<string>
#define Omar_Hafez ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926536
#define ll long long
#define ull unsigned long long
#define lli long long int
using namespace std;
int main()
{
    Omar_Hafez
    int n,sum=0,x; cin >> n; 
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if ((i % 2 != 0 )&&( x % 2 != 0)) sum++;
    }
    return cout<<sum,0;
}
