#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=998244353;
const int siz=1e5;
const long inf=1e9;
int main(){
	string s; cin>>s;
	s = "00" + s;
	int ans = 0;
	for(int i = s.size()-1; i > 0; i--){
		if(s[i] < '5'){
			ans += s[i] - '0';
		}else if(s[i] == '5' && s[i-1] < '5'){
			ans += 5;
		}else{
			ans += '9' - s[i] + 1;
			int j = i - 1;
			while(j >= 0 && s[j] == '9'){
				s[j] = '0';
				j--;
			}s[j] += 1;
		}
	}cout<<ans<<endl;
}