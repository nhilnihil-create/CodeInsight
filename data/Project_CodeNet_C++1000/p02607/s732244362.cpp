#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  unmap  unordered_map<int,int>
#define	 unset	unordered_set<int>
#define  maxpq  priority_queue<int>
#define  minpq  priority_queue<int, vector<int>, greater<int>>
#define ll long long
#define fs first
#define ss second//typedef second ss;
#define fora(i,n) for(int i=0;i<n;i++)
#define endl "\n"
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int ans = 0;
  for(int i=0;i<n;i+=2){
    if(a[i] %2){
      ans++;
    }
  }
  cout<<ans<<endl;
	return 0;
}
