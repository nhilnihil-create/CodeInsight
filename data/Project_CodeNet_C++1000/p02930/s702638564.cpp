#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf ( "%d" , &n );
	for ( int i = 0 ; i < n ; i++ ) 
		for ( int j = i + 1 ; j < n ; j++ ) {
			int tmp = ( i ^ j );
			int ans = 0;
			while ( tmp ) {
				ans++;
				tmp >>= 1;
			}
			printf ( "%d%c" , ans,j==n-1?'\n':' ');
		}
	return 0;
}