#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back

# define inOut(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout);
# define RESET(a) memset(a,0,sizeof(a))
# define MEMO(a) memset(a,-1,sizeof(a))
# define DEBUG puts("Debug-Has-Come-Until-Here")


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
	cin.tie(NULL);

	int i,j;
	for (i=1; i<=9; i++){
		for (j=1; j<=9; j++){
			printf("%dx%d=%d\n", i,j, i*j);
		}
	}
	return 0;
}