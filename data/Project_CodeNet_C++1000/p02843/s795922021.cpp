#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int N = 1e6 + 10, OO = 0x3f3f3f3f, mod = 1e9 + 7;

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

int x , dp[6][N];

int a[] = {100,101,102,103,104,105};

bool solve(int idx , int remW){
	if(remW < 0)
		return 0;
	if(idx == 6){
		if(remW == 0)
			return 1;
		return 0;
	}
	int &ret = dp[idx][remW];
	if(~ret) return ret;
	ret = solve(idx , remW-a[idx]) | solve(idx+1 , remW-a[idx]) | solve(idx+1 , remW);
	return ret;
}


int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	
	scanf("%d" , &x);
	clr(dp , -1);
	if(solve(0 , x))
		puts("1");
	else 
		puts("0");
		
	//for(int idx = 0 ; idx < 6 ; ++i)
		//dp[idx][0] = 1;
	//for(int idx = 0 ; idx < 6 ; ++i){
		//for(int rem = 0 ; rem <= x ; ++rem){
			//dp[idx][rem] = dp[idx+1][rem] | dp[idx][x-rem] | dp[idx+1][x-rem];
		//}
	//}
	//if(dp[6][x])
		//puts("1");
	//else 
		//puts("0");
	
    return 0;
}


