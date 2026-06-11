#include<bits/stdc++.h>
#define f(a,j,k) for(int i = a ; i < j ; i += k)
#define f1(a,j,k) for(int i = a ; i > j ; i -= k)
using namespace std;
typedef long long ll;
typedef vector<long long> vl;
typedef vector<int> vi;
typedef pair<int,int> pri;
typedef pair<long long,long long> prl;
int n;
void dfs(char mx,string s){
	  if(s.length() == n){
			 printf("%s\n",s.c_str());
			 return;
		}
		 f('a',mx+1,1) if(i == mx) dfs(mx+1,s+(char)i);
		 else dfs(mx,s+(char)i);
}
int main() {
	std::ios::sync_with_stdio(false);

	cin >> n;
	dfs('a',"");
	return 0;
}
