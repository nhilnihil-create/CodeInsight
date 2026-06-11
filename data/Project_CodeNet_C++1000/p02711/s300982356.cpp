#include <bits/stdc++.h>
using namespace std;

int main() {
	int i , x , flag=0 , s;
	cin >> s;
    while(s!=0)
    {
    	x=s%10;
    	s/=10;
    	if(x==7)
    	{
    		flag=1;
    		break;
    	}
    }
	if(flag==1)
	cout << "Yes";
	else
	cout << "No";
	return 0;
}