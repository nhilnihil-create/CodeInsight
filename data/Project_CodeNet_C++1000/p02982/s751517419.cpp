#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>

using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	int n, d;
	cin >> n >> d;
	int arr[n][d];
	int i, j, count = 0;
	for(i=0; i<n; i++){
		for(j=0; j<d; j++){
			cin >> arr[i][j];
		}
	}
	//int ans = 0;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			int x = 0;
			for(int k = 0; k<d; k++){
				int diff = abs(arr[i][k] - arr[j][k]);
				x += diff*diff;
			}
			bool flag = false;
			for(int k=0; k<=x; k++){
				if((k*k)==x){
					flag = true;
					break;
				}
			}
			if(flag) count++;
		}
	}
	cout << count << endl;
	return 0;
} 
