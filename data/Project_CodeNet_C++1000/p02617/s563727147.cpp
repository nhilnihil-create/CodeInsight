#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
#define MEM(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mk make_pair
#define pi pair<int, int>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i,a,b) for(int i=a;i>=(b);--i)
using namespace std;
int dt[][2]= {{1,0},{-1,0},{0,1},{0,-1},{0,0}};
//typedef pair<int, int> P;
//priority_queue<int, vector<int>, greater<int> > q;
int main()
{
   IOS;
   int n;
   cin >> n;
   ll ans = 0;
   rep(i,1,n)
   {
       ans += (ll)i*(n-i+1);
   }
   rep(i,1,n-1)
   {
       int u,v;
       cin >> u >> v;
       if(u > v)swap(u,v);
       ans -= (ll)u*(n-v+1);
   }
   cout << ans;
}
