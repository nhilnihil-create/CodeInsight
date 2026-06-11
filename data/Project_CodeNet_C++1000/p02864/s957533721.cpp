#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll N, K;
int H[305];



/*
  DP
    先頭からx列の間にk列操作すると、右端をy行塗った後にz行を塗る必要がある
    z(x,k,y) = ?
    
    列xを操作する場合 
      z(x,k,y) = z(x-1,k-1,y)
    列xを操作しない場合
      z(x,k,Hx) =
        if ( Hx >= y )
          z(x-1,k,y)
        else
          z(x-1,k,y) + (y-Hx)
    
    z(0,0,0) = 0
    
    
*/

struct yz {
	ll y;
	ll z;
};

vector<yz> dp[305][305];

// x : 列(1-300) 
void calc( int x ){
	for ( int k = 0; k <= K; k++ ){
		vector<yz> &d = dp[x][k];
		if ( k ){
			for ( auto it : dp[x-1][k-1] ){  // 列xを操作する場合
				d.push_back(it);
			}
		}
		
		ll min_z = LLONG_MAX;
		for ( auto it : dp[x-1][k] ){ // 列xを操作しない場合
			if ( H[x] >= it.y )
				min_z = min( min_z, it.z );
			else
				min_z = min( min_z, it.z+(it.y-H[x]) );
		}
		if ( min_z != LLONG_MAX ){
			yz c = {H[x],min_z};
			auto it = lower_bound( d.begin(), d.end(), c, [](const yz &l, const yz &r){return l.y<r.y;} );
			if ( it != d.end() && it->y == c.y )
				*it = c;
			else
				d.insert(it,c);
		}
		
		// zが、他のy+z よりも大きい場合は削除
		ll min_yz = LLONG_MAX;
		for ( auto it : d )
			min_yz = min( min_yz, it.y+it.z );
		
		int j = 0;
		for ( auto it : d ){
			if ( it.z > min_yz )
				;
			else
				d[j++] = it;
		}
		d.resize(j);
		
		
		//cout << endl;
		//cout << "calc x=" << x << " k=" << k << endl;
		//for ( auto it : dp[x][k] )
		//	cout << "paint right =" << it.y << " paint add =" << it.z << endl;
	}
}



int main(){
	cin >> N >> K;
	
	for ( int i = 0; i < N; i++ ){
		cin >> H[i+1];
	}
	
	dp[0][0].push_back({0,0});
	
	for ( int x = 1; x <= N; x++ ){
		calc( x );
	}
	
	ll result = LLONG_MAX;
	for ( auto it : dp[N][K] )
		result = min( result, it.y+it.z );
	
	cout << result << endl;
	
	return 0;
}

