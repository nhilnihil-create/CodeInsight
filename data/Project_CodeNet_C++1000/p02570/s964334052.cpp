#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long int li;

#define sc(x) scanf("%lld",&x)
#define pf(x,y) printf("%lld %lld", x,y)
#define pfn printf("\n")
#define fr(i,a,n) for(i = a ; i < n ; i++)



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	li d,t,s;
	cin >> d >> t >> s;
	if(d<=s*t){
		cout << "Yes"<<endl;
	}
	else{
		cout << "No" << endl;
	}
	



	return 0;
}
