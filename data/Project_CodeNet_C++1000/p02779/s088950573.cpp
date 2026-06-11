#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    set<int>arr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
    	int num;
    	cin>>num;
    	arr.insert(num);
	}
	if(arr.size()==n)
	 cout<<"YES";
	else
	 cout<<"NO";
	return 0;
}