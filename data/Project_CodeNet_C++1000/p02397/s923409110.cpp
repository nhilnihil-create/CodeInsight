#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int a,b;
int main()
{while(1){
	cin>>a>>b;
if(!a&&!b) return 0;
cout<<min(a,b)<<' '<<max(a,b)<<endl;
}}