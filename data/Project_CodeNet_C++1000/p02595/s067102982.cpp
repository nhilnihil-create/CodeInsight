#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	int n; double d;
  	cin >> n >> d;
  	int c=0;
  	double x,y;
  	for(int i=0;i<n;i++){
      cin >>x>>y;
      if(d*d>=(x*x+y*y))
         c++;
         }
    cout << c;
    return 0;
}