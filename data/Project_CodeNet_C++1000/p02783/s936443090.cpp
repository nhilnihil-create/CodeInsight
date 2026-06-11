#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        int h,a;
        cin>>h>>a;
        if(h%a == 0) cout<<h/a;
        else cout<<h/a+1;
    }
	return 0;
}