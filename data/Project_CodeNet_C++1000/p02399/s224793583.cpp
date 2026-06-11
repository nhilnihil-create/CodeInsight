#include <iostream>
#include <iomanip>
using namespace std;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int a, b;

int main(){
	cin.tie(0);

    cin>>a>>b;
    
    cout<<(a/b)<<' '<<(a%b)<<' ';
    cout << fixed;
    cout << setprecision(5) << ((double)a/(double)b) <<endl;
    
	return 0;
}

