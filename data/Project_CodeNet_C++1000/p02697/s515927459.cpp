#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m; 
int main()
{
   scanf("%d %d",&n,&m);
   if(n%2==0)n--;
   int l=1,r=n/2+2;
   int t=n/2;
  
		for(int i = 1; i <= m; i++) {
		if(i & 1) {
			printf("%d %d\n", l, l + t);
			t--;
			l++;
		}
		else {
			printf("%d %d\n", r, r + t);
			t--;
			r++;
		}
	}
   

return 0;
}
