#include<bits/stdc++.h>
#define forn(i, n) for(int i=0;i<(int)(n);i++)
#define for1(i, n) for(int i=1;i<=(int)(n);i++)
#define fore(i, l, r) for(int i=(int)(l);i<=(int)(r);i++)
#define ford(i, n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define MAX 1000000007
using namespace std;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<int64_t> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n;
	cin>>n;
	ll max1=INT_MIN;
	ll min1=INT_MAX;
	ll max2=INT_MIN;
	ll min2=INT_MAX;
	for(int i=0;i<n;i++){
	int x,y;
	cin>>x>>y;
	ll sum=x+y;
	ll diff=x-y;
	if(diff>max2)
		max2=diff;
	if(diff<min2)
		min2=diff;
	if(sum>max1)
		max1=sum;
	if(sum<min1)
		min1=sum;
	}
	cout<<max(max1-min1,max2-min2);
	return 0;
}

