#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long i,j,t,n,d,x,y;
    cin>>n>>d;

    int cnt(0);
    while(n--){
    	cin>>x>>y;
    	if(x*x+y*y<=d*d)cnt++;
    }
    cout<<cnt;
 
	
	
	
 
 
 
 
 
 
 
	return 0;
}