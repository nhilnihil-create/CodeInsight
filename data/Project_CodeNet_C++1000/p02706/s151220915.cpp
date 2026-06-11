#include<bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int main()
{
 fastIO();
 long long n , m , free = 0, sum = 0;
 
 cin>>n>>m;
 long long arr[m];
 
 for(int i=0; i<m; i++)
 {
 	cin>>arr[i];
 	sum+=arr[i];
 }
 if(sum>n)
 {
 	free = -1;
 	cout<<free<<endl;
 }
 else
 {
 	free = n - sum;
 	cout<<free << endl;
 }

return 0;
}
