#include<iostream>
#include<stdio.h>
#include<ios>
#include<cmath>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<assert.h>
#include<bitset>
#include<tuple>
#include<climits>
#include<deque>
#include<utility>
#include<unordered_map>
#include<unordered_set>
#include<iterator>
#include<sstream>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define l     long
#define ll    long long
#define nitro ios_base::sync_with_stdio(false);cin.tie(0);
#define vi    vector<int>
#define pub   push_back
#define puf   push_front
#define pob   pop_back
#define pof   pop_front
#define PI    3.1415926535897932384626433
#define endl  '\n'
#define gap   ' '
int main()
{
    nitro
    string s;cin>>s;
    for(int i=0;i<s.size();i+=2)
    {
        if(s.substr(i,2)!="hi") {cout<<"No";return 0;}
    }
    cout<<"Yes";
    return 0;
}
