#include <iostream>
#include <cmath>
const int MAX = 1000001;
using namespace std;

bool p[MAX];

void f(){
    for(int i=0 ; i<MAX ; i++){
        p[i] = (i<=1)? false : true ;
    }
    for(int i=2 ; i <= sqrt(MAX)+1 ; i++){
        if( p[i] ){
            for(int j=i*2 ; j<MAX ; j+=i){
                p[j] = false;
            }
        }
    }
}

int main(){
    int n, ans;

    f();
    while( cin >> n , n ){
		ans = 0;
        for(int i=n+1 ; i <= 2*n ; i++ ){
            if( p[i] ){
				ans++;
			}
        }
		cout << ans << endl;
    }
}