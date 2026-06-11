#include<iostream> 
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#define ll long long
const int N=0x3f3f3f3f;
using namespace std;
int a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main()
{
	int n;
	cin>>n;
	cout<<a[n-1]<<endl;
	return 0;
} 