#include<bits/stdc++.h>
#define si(a) scanf("%d",&a)
#define fore(i,a,b) for(int i=a;i<b;++i)
#define sorte(a) sort(a.begin(), a.end())
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
bool mat[101][101];
int main(){
	int n,k;
	si(n);
	si(k);
	if(k > ((n*n-3*n+2)/2))
		printf("-1\n");
	else{
		fore(i,2,n+1) mat[1][i]=true;
		fore(i,2,n+1) mat[i][1]=true;
		int limi = ((n*n-3*n+2)/2);
		int edge = n-1;
		fore(i,2,n+1){
			if(limi==k)
				break;
			fore(j,i+1,n+1){
				if(limi==k)
					break;
				if(mat[i][j]==false){
					mat[i][j]=true;
					limi--;
					edge++;
				}
			}
		}
		printf("%d\n",edge);
		fore(i,1,n+1){
			fore(j,i+1,n+1){
				if(mat[i][j]){
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	return 0;
}