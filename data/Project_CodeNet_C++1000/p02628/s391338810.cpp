#include<bits/stdc++.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+5;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(x) memset(x,0,sizeof(x))
#define sca(x) scanf("%d",&x)
#define scall(x) scanf("%lld",&x)
#define eps 1e-6
int main()
{
	int n,k;sca(n);sca(k);
	int a[1005];
	for(int i=0;i<n;i++)
	sca(a[i]);
	sort(a,a+n); 
	int ans=0;
	for(int i=0;i<k;i++)
	ans+=a[i];
	cout<<ans<<endl;
 } 