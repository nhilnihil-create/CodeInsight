#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;

int g[2020][2020];
char g2[2020][2020];

int maxi[2020][2020];
int maxj[2020][2020];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	memset(maxi, -1, sizeof maxi);
	memset(maxj, -1, sizeof maxj);
	for(int i=0;i<n;i++){
		string s; cin>>s;
		for(int j=0;j<m;j++)
			g2[i][j] = s[j];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(maxi[i][j]!=-1)continue;
			
			int cont = 0;
			for(int ii=i;ii<n;ii++){
				if(g2[ii][j] == '#')break;
				cont++;
			}
			for(int ii=i;ii<n;ii++){
				if(g2[ii][j] == '#')break;
				maxi[ii][j] = cont;
			}	
			
		}
	
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(maxj[i][j]!=-1)continue;
			int cont = 0;
			for(int jj=j;jj<m;jj++){
				if(g2[i][jj] == '#')break;
				cont++;
			}
			for(int jj=j;jj<m;jj++){
				if(g2[i][jj] == '#')break;
				maxj[i][jj]=cont;
			}
			
		}
	
	}
	
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans = max(ans, maxi[i][j]+maxj[i][j]-1);
		
		}
		
		}
		cout<<ans<<"\n";
	
	return 0;	
}
