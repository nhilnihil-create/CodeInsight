#include <bits/stdc++.h>
using namespace std;



int main()
{
    
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
	long long x;
	cin>>x;

	long long sum ;
	sum = (x/500)*1000;

	x = x%500;

	sum += (x/5)*5;
	x = x%5;
	cout<<sum<<"\n";
	
    return 0;
		
}