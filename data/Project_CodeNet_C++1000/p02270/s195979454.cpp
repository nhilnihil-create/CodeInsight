#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int n, k;
	cin>>n>>k;
	vector< int > w;
	int num, P;
	for( int i=0; i<n; i++ ) {
		cin>>num;
		w.push_back( num );
		P = max( P, num );
	}
	
	int truckCnt, lr, i;
	int left = P;
	
	int right = 100000*10000;
	while( left < right ) {
		P = (left+right)/2;		
		truckCnt = k-1;
		lr = 0;
		for( i=0; i<n; i++ ) {
			if( P < lr+w.at(i) ) {
				truckCnt--;
				if( truckCnt < 0 ) { break; }
				lr = 0;
			}
			lr += w.at(i);
		}
		if( 0 <= truckCnt ) {
			right = P;
		} else {
			left = P+1;
		}
	}
	
	cout<<left<<'\n';
    return 0;
}