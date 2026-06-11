#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int, int> P;
 
int main(){
	  ll n;
	  cin >> n;

		ll m;
		string name;
	  while(n>0){
			--n;
			m=n%26;
			n=(n-m)/26;
			name += 0x61+m;
		}
		reverse(name.begin(),name.end());
    cout << name << endl;
    return 0;
}
