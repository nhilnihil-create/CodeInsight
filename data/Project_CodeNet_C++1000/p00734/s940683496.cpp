#include<iostream>
using namespace std;

int n,m;

int main(){
	int i,j;
	
	while(1){
		cin >> n >> m;
		if( !n)break;
		
		int s[100],t[100];
		int ssum = 0,tsum = 0;
		int kokans = -1, kokant = -1;
		int kokanwa = 100000;
		
		for( i = 0; i < n; i++ )
			cin >> s[i];
		for( i = 0; i < m; i++ )
			cin >> t[i];
		
		for( i = 0; i < n; i++ ){
			ssum += s[i];
		}
		for( i = 0; i < m; i++ ){
			tsum += t[i];
		}
		
		for( i = 0; i < n; i++ ){
			for( j = 0; j < m; j++ ){
				if( ssum+t[j]-s[i] == tsum-t[j]+s[i] ){
					if( kokanwa > s[i]+t[j] ){
						kokanwa = s[i]+t[j];
						kokans = s[i];
						kokant = t[j];
					}
				}
			}
		}
		if( kokans == -1 )
			cout << "-1" << endl;
		else{
			cout << kokans << " " << kokant << endl;
		}
	}
	return 0;
}