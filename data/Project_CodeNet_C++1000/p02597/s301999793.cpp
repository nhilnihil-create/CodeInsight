#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char s[200005];
int main()
{
    int n,w;
    cin >> n >> s;
    int ans = 0, sum = 0;
     for(int i = 0; i < n; i++)
     {
         if(s[i] == 'R')
         sum++;
     }
    for(int i = 0; i < sum; i++)
    {
        if(s[i] == 'R')
        ans++;
    }
    cout << sum-ans << endl;

}