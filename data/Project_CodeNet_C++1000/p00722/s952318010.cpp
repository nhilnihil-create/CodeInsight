#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
char p[MAX] = {0};

void f(){
	for(int i=2 ; i < MAX ; i++ )
		p[i] = 1;
	for(int i=2 ; i*i < MAX ; i++ ){
		if( p[i] ){
			for(int j=i*2 ; j < MAX ; j += i ){
				p[j] = 0;
			}
		}
	}
}

int main(){
	int a,d,n,ans;
	f();

	while( cin >> a >> d >> n , a||d||n ){
		vector<int> v;

		for(int i=a ; v.size() != n ; i += d ){
			if( p[i] ){
				v.push_back( i );
			}
		}
		cout << v[v.size()-1] << endl;
	}
}