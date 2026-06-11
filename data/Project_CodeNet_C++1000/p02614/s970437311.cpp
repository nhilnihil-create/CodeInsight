#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,slot[100],a[100],l,r,x,jwb,now,m;
vector<ll>h[100050],w[100050];
bool flag[100];
void f(int idx) {
	if (idx>k) {
		now++;
		for (int i=1; i<=k; i++){
			h[now].push_back(slot[i]);
		}
		return;
	}
	else {
		for (int i=slot[idx-1]+1; i<=n; i++){
			if (!flag[i]){
				flag[i]=1;
				slot[idx]=i;
				f(idx+1);
				flag[i]=0;
			}
		}
	}
}
void f2(int idx) {
	if (idx>k) {
		now++;
		for (int i=1; i<=k; i++){
			w[now].push_back(slot[i]);
		}
		return;
	}
	else {
		for (int i=slot[idx-1]+1; i<=m; i++){
			if (!flag[i]){
				flag[i]=1;
				slot[idx]=i;
				f2(idx+1);
				flag[i]=0;
			}
		}
	}
}
int main (){
	ll sakura,jwb=0;
	cin >> n >> m >> sakura;
	now=1;
	for (k=1; k<=n; k++){
		f(1);
	}
	char c[100][100];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> c[i][j];
		}
	}
	now=1;
	memset(flag,0,sizeof flag);
	memset(slot,0,sizeof slot);
	for(k=1; k<=m; k++){
		f2(1);
	}
	for(int i=1; i<=pow(2,n); i++){
		for(int j=1; j<=pow(2,m); j++){
			bool cekx[100],ceky[100];
			memset(cekx,0,sizeof cekx);
			memset(ceky,0,sizeof ceky);
			for(int ii=0; ii<h[i].size(); ii++){
				cekx[h[i][ii]]=1;
			}
			for(int jj=0; jj<w[j].size(); jj++){
				ceky[w[j][jj]]=1;
			}
			ll cnt=0;
			for(int ii=1; ii<=n; ii++){
				for(int jj=1; jj<=m; jj++){
					if(cekx[ii]==0 && ceky[jj]==0 && c[ii][jj]=='#')cnt++;
				}
			}
			if(cnt==sakura)jwb++;
		}
	}
	cout << jwb << endl;
}
