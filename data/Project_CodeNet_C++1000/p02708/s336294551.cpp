#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long pre[200005]={0};
const int mod = 1000000007;
int main()
{
    int n,k;
    cin >> n >> k;
    long long num = 0;
    for(int i=1;i<=n;i++)
        pre[i]=i+pre[i-1];
    pre[n+1]=pre[n];
    long long ans =0 ;
    for(int i=k;i<=n+1;i++){
		//cout <<  pre[n]-pre[n-i]-pre[i-1]+1 << endl;
        ans = (ans + pre[n]-pre[n-i]-pre[i-1]+1)%mod+mod;
    }
	if(k>n)
		cout << 1 << endl;
	else
    	cout << ans%mod << endl;
    return 0;
}
