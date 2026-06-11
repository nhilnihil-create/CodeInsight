#include<bits/stdc++.h>
#define pb push_back
#define inf 0x3f3f3f3f
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define mem(a,val) memset(a,val,sizeof(a))
#define mkp make_pair
#define all(n) (n).begin(),(n).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n;
void dfs(string s, char x){
	if(s.size()==n){
		cout<<s<<endl;
		return ;
	}

	for(char i='a' ; i<=x ; i++){
		if(x == i){
			dfs(s+i,x+1);
		}
		else{
			dfs(s+i,x);
		} 
			
	}
}
int main(){
	cin>>n;
	dfs("",'a');
}