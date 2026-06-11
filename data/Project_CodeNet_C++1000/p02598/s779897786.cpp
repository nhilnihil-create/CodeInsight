
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define inf    0x3f3f3f3f
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
typedef vector<int>      vi;
typedef vector<bool>     vb;
#define INF (int)1e15
#define MOD 1000000007

#define access(i) a[i/3][i%3]
//#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})

int n,k;
vector<int> a;

bool ok(int md){
	int cnt = 0;
	for(int  i = 0; i < n; i++){
		cnt += (a[i] - 1) / md;
	}
	//cout<<" :: "<<cnt<<" :: "<<endl;
	if(cnt <= k)
            return true;

  return false;
}

int main(){

	cin >> n >> k;
	a.resize(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int low = 1;
	int high = 1e9;
	int ans = 1e9;

	while(low <= high)
      {
		int md = (low + high) / 2;

    //cout<<low<<" . "<<md<<" ? "<<high<<endl;

		if(ok(md)){
			high = md - 1;
			ans = min(ans,md);
		}else{
			low = md + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}
