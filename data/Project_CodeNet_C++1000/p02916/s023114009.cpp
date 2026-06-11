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
	vector<int> dish,gains,more;
	for(int i=0;i<n;i++){
		int a;cin>>a; a--;
		dish.pb(a);
	}
	for(int i=0;i<n;i++){
		int b;cin>>b;
		gains.pb(b);
	}
	for(int i=0;i<n-1;i++){
		int c;cin>>c;
		more.pb(c);
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=gains[dish[i]];
		if(i>0&&dish[i]==dish[i-1]+1){
			ans+=more[dish[i-1]];
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
