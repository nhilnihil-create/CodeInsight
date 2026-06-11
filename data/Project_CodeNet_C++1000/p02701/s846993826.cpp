#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;

int main(void){
	scanf("%d",&n);
	set<string> se;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		se.insert(s);
	}
	printf("%d\n",(int)se.size());
	return 0;
}
