#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p[100], q[100], x=0, i;
    cin>>n;
    for(i=0; i<n; i++)
    	cin>>p[i], q[i]=p[i];
    sort(p, p+n);
    for(i=0; i<n; i++)
    {
    	if(p[i]!=q[i])
    		x++;
    }
    (x<=2)?	cout<<"YES" : cout<<"NO";
}
    