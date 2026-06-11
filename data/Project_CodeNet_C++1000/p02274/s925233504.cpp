//merge ha bubble (stable sort)
//compiledef
#include <bits/stdc++.h>
#define rep(i, n) for(i=0;i<(n);i++)
#define per(i, n) for(i=(n);i>0;i--)
#define repx(i, n, x) for(i=(x);i<(n);i++)
#define xper(i, n, x) for(i=(n);i>(x);i--)
#define pback push_back

//c++def
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
ll merge(int *a, int left, int mid, int right){
	ll cnt=0;
	int i;
	int j;
	int k;
	int n1=mid-left;
	int n2=right-mid;
	vector<int> L;
	vector<int> R;
	rep(i, n1) L.pback(a[left+i]);
	rep(i, n2) R.pback(a[mid+i]);
	L[n1] = 2e9;
	R[n2] = 2e9;
	for(i=0, j=0, k=left;k<right;k++){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
			cnt += n1 - i;//mid-left-i == try_bubble_swap (ex. 5 2 1 is 1+1(merge swap)=2(bubble swap 1))
		}
	}
	return cnt;
}

ll mergesort(int *a, int left, int right){
	ll a1=0, a2=0, a3=0;
	if(left+1<right){
		int mid = (left+right)/2;
		a1 = mergesort(a, left, mid); //bunkatsu(recursion)
		a2 = mergesort(a, mid, right);
		a3 = merge(a, left, mid, right);
	}
	return a1+a2+a3;
}

int main(){
	int i;
	int n;
	cin >> n;
	int a[n];
	rep(i, n) scanf("%d",&a[i]);
	ll cnt = mergesort(a, 0, n);
	printf("%lld\n", cnt);
}

