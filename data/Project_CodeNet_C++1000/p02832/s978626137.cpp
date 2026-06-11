#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		int c = 1;
		int k = 0;
		for(int i = 0;i<n;i++){
		
			if(a[i] ==c){
				c++;
				k++;
			}
		}
		if(k==0){
			cout<<-1;
			return 0;
		}
		cout<<(n-k);




}

