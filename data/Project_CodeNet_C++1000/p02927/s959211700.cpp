#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	int m,d;
	cin>>m>>d;

	if(d<22){
		cout<<0<<endl;
		return 0;
	}

	int ans=0;
	for (int i = 1; i <= m; ++i){
		for (int j = 22; j <= d ; ++j){
			if(((j/10)*(j%10))==i && j/10>=2&&j%10>=2){
				ans++;
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}
