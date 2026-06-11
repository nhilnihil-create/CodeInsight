// https://atcoder.jp/contests/abc152/tasks/abc152_d
// 
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define is_in(i, s) (s.find(i) != s.end())
#define all(x) (x).begin(),(x).end()
#define outl(x) cout<<x<<endl
#define outsp(x) cout<<x<<" "
typedef long long ll;
typedef pair<int,int> P;


#define MAX_N 1000000005

int log10(int v){
	int ret=0;
	while(v>0){
		v/=10;
		ret++;
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	ll ans = 0;
	int n_kn = log10(n);
	int n_l = n/(int)pow(10,n_kn-1);
	int n_r = n%10;
	int n_c = (n - n_l*(int)pow(10,n_kn-1))/10;
	for(int a=1;a<=n;a++){
		int kn = log10(a);
		int l = a/(int)pow(10,kn-1);
		int r = a%10;
		if(r==0)continue;
		if(l==r){
			if(l<=n)ans++; // b=l (1桁)の場合
		}
		rep(j,n_kn-2){
			ans += (ll)pow(10,j);
		}
		if(n_kn>1){
			if(r<n_l){
				ans += (ll)pow(10,n_kn-2);
				// outsp(a);outl(ans);
			}else if(r==n_l){
				if(n_kn==1){
					ans ++;
				}else{
					if(l<=n_r){
						ans += n_c + 1;
					}else{
						ans += n_c;
					}

				}
				
			}
		}
	}
	outl(ans);
    return 0;
}

