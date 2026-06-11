#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string n; cin>>n;
	
	int x = int(n.back() - '0');
	if(x == 3)
		cout<<"bon\n";
	else if(x == 2 || x== 4 || x==5 ||x==7 || x==9)
		cout<<"hon\n";
	else cout<<"pon\n"; 	

	return 0;	
}
