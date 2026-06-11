#include<bits/stdc++.h>
#define endl '\n'
#define int long long
 
using namespace std;
 
int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int money = 1000;

	//int ans=0;
	int best_sell=0;
	int cant=0;
	int best_item=INT_MAX;

	for(int i=0;i<n;i++){
		if(v[i]<best_item){
			best_item=v[i];
			money+=best_sell;
			cant = money/v[i];
			//ans+=best_sell;
			best_sell=0;
		}
		else if(i && v[i]<v[i-1]){
			best_item=v[i];
			money+=best_sell;
			cant = money/v[i];
			//ans+=best_sell;
			best_sell=0;
		}
		else if(i==n-1){
			best_sell=max(best_sell,(v[i]-best_item)*cant);
			money+=best_sell;
		}
		else{
			best_sell=max(best_sell,(v[i]-best_item)*cant);
		}
	//	cout<<best_item<<"   "<<money<<endl;
	}

	cout<<money<<endl;	
	
	return 0;
}
