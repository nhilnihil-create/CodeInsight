#include<iostream>
#include<algorithm>
using namespace std ; 
const int N = 1e6 + 1e5 ; 
long long pt[N] , dd[N] , mark[N] , x , y , a , b , c , st1 , st2 , st3 , ans = 0 ;
bool cmp(int i , int j){
	return pt[i] > pt[j] ;
}
int main(){
	cin>>x>>y>>a>>b>>c;
	for(int i = 1 ; i <= a + b + c ; i ++){
		cin>>pt[i] ;
		dd[i] = i ;
		if(i <= a) {
			mark[i] = 1 ;
		}else if(i <= a + b ){
			mark[i] = 2 ;
		}else{
			mark[i] = 3 ;
		}
	}
	sort(dd + 1 , dd + a + b + c + 1 , cmp) ;
	long long n = a + b + c ;
	for(int i = 1 ; i <= n ; i ++){
		if(mark[dd[i]] == 1 && st1 < x){
			st1 ++ ;
			ans += pt[dd[i]] ;
		}else if(mark[dd[i]] == 2 && st2 < y){
			st2 ++ ;
			ans += pt[dd[i]] ;
		}else if(mark[dd[i]] == 3 ){
			st3 ++ ;
			ans += pt[dd[i]] ;
		}
		if(st1 + st2 + st3 == x + y) break ;
	}
	cout<<ans<<endl ;
	return 0 ;
} 