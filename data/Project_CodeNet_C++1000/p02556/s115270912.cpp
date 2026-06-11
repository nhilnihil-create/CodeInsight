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

const int N = 2e5+5;
ll cmp1[N],cmp2[N];

int main()
{
   IOS;
   int n;
   cin >> n;
   rep(i,1,n)
   {
       ll x,y;
       cin >> x >> y;
       cmp1[i] = x+y;
       cmp2[i] = x-y;
   }
   sort(cmp1+1,cmp1+1+n);
   sort(cmp2+1,cmp2+1+n);
   cout << max(cmp1[n]-cmp1[1],cmp2[n]-cmp2[1]);
}
