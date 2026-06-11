#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
	int n; cin >> n ;
	int a[n];
	for(int i=0 ; i < n ; i++) cin >> a[i];
	sort(a,a+n);
	int count =0;
	for(int i=0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			int x= a[i],y=a[j];
			int z= x+y; // search for the third such that a+b > c 
			int idx = lower_bound(a+j+1, a+n,z)-a;
			idx--;
			if(idx>j)
			count+=(idx-j);
		}
	}
	cout << count << endl;
}