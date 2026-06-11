#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //float b= n;
    //int c=0;
    cin>>n;
    if(n%2==0)
    {
    	cout<<"0.5000000000"<<endl;
	}
	else
	{
		cout<<fixed<<setprecision(10)<<(long double)(n/2+1)/n<<endl;
	}
}