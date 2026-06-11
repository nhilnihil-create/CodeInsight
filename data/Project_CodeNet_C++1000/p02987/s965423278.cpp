/******* all required header files *******/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

/*****All definitions*******/
#define w(t) int t; cin>>t; while(t--)
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define mp make_pair
#define ll long long int
#define pb push_back
#define F first
#define S second
/***************************/

int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    string str;
    cin>>str;
    set<char> s;
    for(int i = 0; i < str.size(); i++)
    {
        char a = str[i];
        s.insert(a);
    }
    vector<int> v;
    for(auto itr = s.begin(); itr != s.end(); itr++)
    {
        int a = count(v.begin(), v.end(), *itr);
        v.pb(a);
    }
    
    if(v.size() == 2 && v[0] == v[1])
    {
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}