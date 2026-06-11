#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	lint x; cin>>x;
	
	cout<<(x/500)*1000 + ((x%500)/5)*5<<"\n";

	return 0;	
}
