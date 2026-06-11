// atcoder 175

//A
/*
#include <iostream>
using namespace std;
#define ll  long long
#define M 1000000007
#define tc int t; cin>>t; while(t--)
#include <cstring>
int main(){
	string s;
	cin>>s;
	int l = 0, maxL = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'R' && maxL <= l){
			l++;
			maxL = l; 
		}
		else if(s[i] == 'S'){
			l = 0; 
		}
	}
	cout << maxL << endl;
	return 0;
}
*/

// B
#include <iostream>
using namespace std;
#define ll  long long
#define M 1000000007
#define tc int t; cin>>t; while(t--)
#include <cstring>

ll triangle(ll arr[], int n){
	ll ans = 0;

	for(int  i = 1; i <= n-2; i++){
		for(int j = i+1; j <= n-1; j++){
			for(int k = j+1; k <= n; k++){
				bool a = arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k];
				bool b = arr[i] + arr[j] > arr[k] && arr[j] + arr[k] > arr[i] && arr[i] + arr[k] > arr[j];
				if( a && b){
					ans++;
				}
			}
		}
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	ll arr[n];
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	cout << triangle(arr , n) << endl;
}
