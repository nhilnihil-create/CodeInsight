#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss string
int main()
{
	int wa[105000],n,m,acnum=0,wanum=0;
    bool ac[105000];
	cin >> n >> m;
	for(int i =1;i<=n;i++)

	{
		wa[i]=0;
		ac[i]=false;
	}
    while(m--)
    {
    	int p;
    	ss s;
    	cin >> p >> s;
         if(ac[p]) continue;
        if(s == "AC") {
            ac[p] = true;
            acnum++;
            wanum += wa[p];
        } else if(s == "WA") {
            wa[p]++;
        }
    }
    	cout << acnum << " " << wanum <<"\n";
}