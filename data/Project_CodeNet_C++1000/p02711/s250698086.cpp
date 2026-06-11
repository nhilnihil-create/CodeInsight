#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,x,f=0;
	cin >> n;
	while(n)
    {
        f = n%10;
        n /= 10;
        if(f == 7)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
