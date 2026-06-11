#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500+50];
int x[100000+50],l[100000+50];
vector <pair <int,int> > v;

// bool cmp(pair <int,int> v1, pair <int,int> v2){

// }
signed main(){
    ios::sync_with_stdio(false);
    
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>l[i];
		v.push_back({x[i]-l[i],x[i]+l[i]});
	}
	sort(v.begin(),v.end());

	int rbnd=-1000000000000000;


	int cnt=0;

	for(int i=0;i<n;i++){
		if(v[i].first>=rbnd){
			cnt++;
			rbnd=max(rbnd,v[i].second);
		}
		else{
			rbnd=min(rbnd,v[i].second);
		}
	}

	cout<<cnt;

}
/*

Mistakes to take care of-

1. For string s, s+=a is similar to appending to s. s = s + a takes O|s| + O|a| time. 
Relevant problem where I made mistake - https://codeforces.com/contest/1326/problem/D2

2. Try using constant value of N to declare arrays, etc. Else you might get hacked / FST.
Relevant problem where I made a mistake - https://codeforces.com/contest/1307/problem/D

3. While exponentiation, avoid modding the exponent. Or mod with mod-1.
Relevant problem where I made a mistake - https://codeforces.com/contest/1332/problem/E

4. modulo operator (%) in c++ returns the sign of the divisor.
Eg. (-1%8) = -1
Relevant problem where I made a mistake - https://codeforces.com/contest/1345/submission/79809463
*/
