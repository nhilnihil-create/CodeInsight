#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 1e5+5;
ll n, arr[nax];
bool salah=0;
unordered_map<int, int>book;

int main(){
	IOS
	cin >> n; 
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			if(!book[arr[i]]){
				if(arr[i]-1==arr[i+1]){
					arr[i]--;
					book[arr[i+1]]=1;
				}
				else{
					salah=1;
					break;
				}
			}
			else{
				salah=1;
				break;
			}
		}
	}
	if(salah){
		cout << "No" << '\n';
	}	
	else{
		cout << "Yes" << '\n';
	}
	return 0;
}
