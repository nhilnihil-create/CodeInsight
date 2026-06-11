#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#define ll long long
#define MAX 1000003
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define input(a) for(int i=0;i<n;i++) cin>>a[i];
using namespace std;
int arr[19]={0};
int main(){
	IOS;
	int m,d;
	cin>>m>>d;
	int ctr=0;
	for(int i=1;i<=m;i++){
		for(int j=22;j<=d;j++){
			if(j==100)
				break;
			int d1=j%10;
			if(d1<2)
				continue;
			int d10=j/10;
			if(d10<2)
				continue;
			if(i==d1*d10){
				//cout<<i<<" "<<j<<endl;
				ctr++;
			}
		}
	}

	cout<<ctr;
return 0;
}