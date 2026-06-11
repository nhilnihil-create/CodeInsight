#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) (int)x.size()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define fill(a,v) memset(a,v,sizeof(a))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define INF 0x3f3f3f3f//infinity for integers
#define JJ ios_base::sync_with_stdio(0); cin.tie(0)//input fast
#define MOD 1000000007
#define hash(n) unordered_map<int,int>mp(n)
bool comp(int a, int b){
	return a>b;
}

int main() 
{ 
	JJ;
	int n; cin>>n;
	int r=n%10;
	if(r==0 || r==1|| r==6 || r==8){
		cout<<"pon"<<endl;
	}
	else if(r==3)
		cout<<"bon"<<endl;
	else
		cout<<"hon"<<endl;




	return 0;



    
} 