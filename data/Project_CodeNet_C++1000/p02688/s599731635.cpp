#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int N = 2e5 + 10, OO = 0x3f3f3f3f, mod = 1e9 + 7;

#define PI acos(-1)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(v) ((v).begin()), ((v).end())
#define SZ(v) ((int)((v).size()))
//int dx[] = {1, 0, -1, 0};
//int dy[] = {0, 1, 0, -1}; //4 Direction
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//

int n,  k;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	
	scanf("%d %d", &n , &k);
	map < int , int > vis;
	for(int i = 0 ; i < k ; ++i){
		int x;
		scanf("%d",  &x);
		for(int j = 0 ; j < x ; ++j){
			int rkm;
			scanf("%d", &rkm);
			vis[rkm]++;
		}
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++i)
		if(!vis[i])
			cnt++;
		
	printf("%d\n", cnt);
	
	
	
    return 0;
}


