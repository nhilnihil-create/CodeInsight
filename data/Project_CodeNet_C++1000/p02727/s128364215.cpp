#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+7;
int a1[N],a2[N],a3[N];
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	for(int i=0;i<a;i++){
		cin>>a1[i];
	}
	for(int i=0;i<b;i++){
		cin>>a2[i];
	}
	for(int i=0;i<c;i++){
		cin>>a3[i];
	}
	ll sum = 0;
	sort(a1,a1+a,greater<int>()); sort(a2,a2+b,greater<int>() ); sort(a3,a3+c,greater<int>() );
	for(int i=0;i<x;i++){
		sum += a1[i];
	}
	for(int i=0;i<y;i++){
		sum += a2[i];
	}
	int i=x-1,j=y-1,k = 0;
	while(1){
		int t = k;
		if(i<0&&j<0||k>=c) break;
		if(i<0){ 
			if(a2[j]<a3[k]){
				sum = sum + a3[k] - a2[j];
				j--; k++;
			}		
		}
		else if(j<0){
			if(a1[i]<a3[k]){
				sum = sum + a3[k] - a1[i];
				i--; k++;
			}
		}
		else{
			if(a1[i] <= a2[j]&&a1[i]<a3[k]){
				sum = sum + a3[k] - a1[i];
				i--; k++;
			}
			else if(a2[j] <= a1[i]&&a2[j]<a3[k]){
				sum = sum + a3[k] - a2[j];
				j--; k++;
			}
		}
		if(t==k) break;
	}
	cout<<sum<<endl;
}