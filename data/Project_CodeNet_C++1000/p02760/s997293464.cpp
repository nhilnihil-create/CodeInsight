#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;

int n;
int a[10][10];
bool b[10][10];
set<int> st;

int mvx[10] = {-1, 0, 1, 1, 1, 0, -1, -1};
int mvy[10] = {-1, -1, -1, 0, 1, 1, 1, 0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		st.insert(x);
	}
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(st.count(a[i][j]))b[i][j] = true;
		}
	}
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(!b[i][j])continue;
			for(int k=0;k<8;k++){
				if(b[i+mvx[k]][j+mvy[k]] && b[i-mvx[k]][j-mvy[k]]){
					cout<<"Yes";
					return 0;
				}
			}
		}
	}
	
	cout<<"No";
	return 0;
}

