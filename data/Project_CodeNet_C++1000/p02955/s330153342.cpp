#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

#define P pair<lli,lli>

signed main(){

	lli n,k;
	cin>>n>>k;

	vector<lli> a(n);
	lli sum = 0;
	REP(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}

	priority_queue<lli> yaku;
	for(lli i=1;i*i <= sum;i++){
		if(sum%i==0){
			yaku.push(i);
			if(sum/i!=i)yaku.push(sum/i);
		}
	}

	sort(a.begin(),a.end());

	lli small=1,large = 1e10;

	while(yaku.size()){
		lli top = yaku.top();
		yaku.pop();
		vector<lli> b(n);
		REP(i,0,n)b[i] = a[i]%top;
		sort(b.begin(),b.end());

		lli cnt = 0;
		lli left = 0,right = n-1;
		while(left<right){
			lli num = b[left];
			b[left] = 0;
			cnt += num;
			left++;
			while(num > top - b[right]){
				num -= (top-b[right]);
				b[right] = 0;
				right--;
			}
			b[right] += num;
		}
		if(cnt <= k){
			cout<<top<<endl;
			return 0;
		}
	}
	cout<<1<<endl;

	return 0;
}