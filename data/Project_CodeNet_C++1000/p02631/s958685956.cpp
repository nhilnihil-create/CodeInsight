#include<bits/stdc++.h>
 
using namespace std;

#define debug(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;

#define N 200005
int xa[N], an[N];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> xa[i];
	int xo=0;
	for(int i=0; i<n; i++) xo ^= xa[i];
	
	for(int i=0; i<n; i++){
		if(i!= 0) cout << " ";
		cout << (xo^xa[i]);
	}
	puts("");
 
    return 0;
}
