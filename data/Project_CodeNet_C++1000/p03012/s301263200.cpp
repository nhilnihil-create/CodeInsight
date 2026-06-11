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
#include<iomanip>
#include<ext/pb_ds/assoc_container.hpp>
#include<chrono>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int            int64_t
#define double         long double
#define nitro          ios_base::sync_with_stdio(false);cin.tie(0);
#define vi             vector<int64_t>
#define pub            push_back
#define puf            push_front
#define pob            pop_back
#define pof            pop_front
#define PI             3.1415926535897932384626433832795
#define read(a)        for(auto& x : a) cin>> x
#define endl           '\n'
#define gap            ' '
#define min3(a,b,c)    min(a, min(b, c))
#define max3(a,b,c)    max(a, max(b, c))
#define MOD            1000000007
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int32_t main()
{
    nitro
    int n;cin>>n;
    int a[n];read(a);
    int i=0,j=n-1,si=0,sj=0;
    while(i<=j)
    {
    	if(si<=sj) si+=a[i++];
    	else if(sj<si) sj+=a[j--];
    }
    cout<<abs(si-sj);
    return 0;
}