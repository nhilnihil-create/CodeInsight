#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n){
		if(n==0)
			break;
		int sum[5000];
		int ma;
		for(int i=0;i<n;i++){
			cin >> sum[i];
			if(i!=0){
				sum[i] += sum[i-1];
				ma = max(ma,sum[i]);
			}
			else
				ma = sum[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ma = max(ma,sum[j]-sum[i]);
			}
		}
		cout << ma << endl;
	}
	return 0;
}