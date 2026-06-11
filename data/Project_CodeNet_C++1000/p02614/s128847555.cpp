#include <bits/stdc++.h>

#define mp make_pair
#define ff first
#define ss second
#define pii pair <int,int>
#define pb push_back
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std ;
typedef long long ll ;
char c[7][7] ;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int h=0,w=0,k=0,black=0 ;
	cin >> h >> w >> k;
	for(int i =1 ;i<= h ; i++){
		for(int j = 1 ; j<=w ; j++){
			cin >> c[i][j] ;
			if(c[i][j] == '#'){
				black++ ;
			}
		}
	}
	int ans=0 ;
	int x =0 , zart=0 ;
	vector <int> satr ,soton ;
	for(int mask=0 ; mask < (1<<(h+w)) ; mask++){
		for(int i =0 ; i<(h+w) ;i++){
			if(((1<<i) & mask)){
				if(i <= h-1){
					satr.pb((i+1)) ;
				}
				else{
					soton.pb((i-h+1)) ;
				}
			}
		}
		for(int i : satr ){
			for(int j : soton){
				if(c[i][j] == '#'){
					zart++ ;
				}
			}
		}
		for(int i : satr){
			for(int j=1 ; j <= w ; j++){
				if(c[i][j] == '#'){
					x++ ;
				}
			}
		}
		for(int j : soton){
			for(int i =1 ; i<= h ; i++){
				if(c[i][j] == '#'){
					x++ ;
				}
			}
		}
		if((x-zart) == (black-k)){
			ans++;
		}
		satr.clear() ;
		soton.clear() ;
		zart =0 ;
		x = 0 ;
	}
	cout << ans ;
	return 0 ;
}
