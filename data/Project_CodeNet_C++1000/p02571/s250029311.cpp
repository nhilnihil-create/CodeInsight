#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef complex <double> cp;
#define debug(a) cout<<#a<<":"<<a<<endl;
#define fr freopen("in.txt","r",stdin);
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
const double PI = acos(-1);
const int INF=0x3f3f3f3f;
const int N=1e6+7;
const int mod=1e9+7;
int maxn,minn;
int T,n,m,q;
int d,t,v;
string s1, s2;
int len1, len2;

int main(){
	cin >> s1 >> s2;
	len1 = s1.size();
	len2 = s2.size(); 
	minn = INF;
	for(int i = 0; i + len2 - 1 < len1; i ++ ){
		int ans = 0;
		for(int j = 0; j < len2; j ++ ){
			if(s1[i + j] != s2[j]){
				ans ++ ;
			}
		}
		minn = min(minn,ans);
	}
	cout << minn << endl;
	


	return 0;
}

