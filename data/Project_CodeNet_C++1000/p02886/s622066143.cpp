#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second
#define all(x) x.begin(), x.end()
#define sz(x) (x).size()


ll sum(int n);

void go(){
	int n;cin>>n;
	vector<int> nums(n);
	for(int& x : nums) cin>>x;
	int ans=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			ans+=nums[i]*nums[j];
		}
	}
	cout << ans;
}
int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}

ll sum(int n){                
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
