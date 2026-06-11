#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,to) for(int i=x;i<to;i++)

long long cnt;
int v,j;
vector<int> G;

void insert(long int a[],int n, int g){
	rep(i,g,n){
		v = a[i];
		j = i-g;
		while(j>=0&&a[j]>v){
			a[j+g] = a[j];
			j = j-g;
			cnt++;
		}
		a[j+g] = v;
	}
}

void shellsort(long int a[],int n){
	for(int h=1;;){
		if(h>n) break;
		G.push_back(h);
		h = 3*h+1;
	}
	for(int i=G.size()-1;i>=0;i--) insert(a,n,G[i]);
}

int main() {
	int n; cin >> n;
	cnt=0;
	long int a[1000000];
	
	rep(i,0,n) cin >> a[i];
	
	shellsort(a,n);
	
	cout << G.size() << endl;
	for(int i=G.size()-1;i>=0;i--){
		if(i==G.size()-1) cout << G[i];
		else cout << " " << G[i];
	}
	cout <<endl<<cnt<<endl;
	rep(i,0,n) cout << a[i] <<endl;
	
	return 0;
}
