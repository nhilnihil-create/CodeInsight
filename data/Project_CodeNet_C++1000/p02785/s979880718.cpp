#include <iostream>

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int find_pivot(int* a, int i, int j){
	int k = i+1;
	while(k <= j && a[i] == a[k]) k++;
	if(k>j) return -1;
	if(a[i] >= a[k]) return i;
	return k;
}

int partition (int* a, int i, int j, int x){
	int l=i, r=j;
	while(l <= r){
		while(l <= j && a[l] < x) l++;
		while(r >= i && a[r] >= x) r--;
		
		if(l > r) break;
		int tmp = a[l];
		a[l] = a[r];
		a[r] = tmp;
		l++;
		r--;
	}
	return l;
}

void quick_sort(int* a, int i, int j){
	if(i == j) return;
	int p = find_pivot(a, i, j);
	if(p != -1){
		int k = partition(a, i, j, a[p]);
		quick_sort(a, i, k-1);
		quick_sort(a, k, j);
	}
}

int main(){
	int n,k;
	cin >> n >> k;
	int h[n];
	long long sum = 0;
	rep(i,n) { cin >> h[i]; sum+=h[i]; }
	
	quick_sort(h, 0, n-1);
	
	for(int i = 0; i < k && i < n; i++){
		sum -= h[n-1-i];
		h[n-1-i] = 0;
	}
	
	cout << sum << endl;
	
}