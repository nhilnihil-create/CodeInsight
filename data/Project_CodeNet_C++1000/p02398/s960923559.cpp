#include <iostream>
using namespace std;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int a, b, c;

int main(){
	cin.tie(0);
	
    cin>>a>>b>>c;
    
    int d = 0;
    for_(i, a, b+1) {
        if(c%i==0)d++;
    }
    cout<<d<<endl;
	return 0;
}

