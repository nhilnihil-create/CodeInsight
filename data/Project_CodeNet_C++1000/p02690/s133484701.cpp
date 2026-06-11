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

ll x;


ll fastPower(ll b , ll p){
    if(p == 0)
        return 1;
    
    ll ret = fastPower(b,p/2);
    return (p&1 ? ret*ret*b : ret*ret);

}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	
	scanf("%lld", &x);
	map < ll , ll > vis;
	for(ll i = -3000 ; i <= 3000 ; ++i)
		vis[fastPower(i , 5)] = i;
	
	for(ll j = 0 ; j <= 3000 ; ++j)
		if(vis[fastPower(j , 5) - x])
			return printf("%lld %lld\n" , j , vis[fastPower(j , 5) - x]) , 0;
	
	
	
    return 0;
}


