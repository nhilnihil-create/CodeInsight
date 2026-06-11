#include<bits/stdc++.h>
using namespace std;
#define mp make_pair 
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

int k,a,b;

int bisa(){
	for (int i=a;i<=b;i++){
		if (i % k == 0) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	cin >> k >> a >> b;
	if (bisa()) cout << "OK" << "\n";
	else cout << "NG" << "\n";
	return 0;
}