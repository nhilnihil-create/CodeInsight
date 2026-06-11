#include<bits/stdc++.h>
using namespace std;
int main()
{

		int h,a;
		cin>>h>>a;
		int ans=h/a;
		h=h%a;
		if(h>0)
		ans++;
		cout<<ans;
}