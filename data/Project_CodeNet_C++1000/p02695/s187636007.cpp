#include<bits/stdc++.h>
using namespace std;
struct point{
	int a,b,c,d;
};
int n,m,q;
point query[55];
int arr[15];
int mx,call;
void f(int curr,int before){
	call++;
	for(int i=before; i<=m; i++){
		arr[curr] = i;
		if(curr==n){
			int sum = 0;
			for(int j=0; j<q; j++){
				point&k = query[j];
				if(arr[k.b]-arr[k.a] == k.c) sum+=k.d;
			}
			mx = max(mx,sum);
		}
		else f(curr+1,i);
	}
}

int main(){
	cin>>n>>m>>q;
	for(int i=0; i<q; i++){
		cin>>query[i].a>>query[i].b>>query[i].c>>query[i].d;
	}
	f(1,1);
	cout<<mx;
}