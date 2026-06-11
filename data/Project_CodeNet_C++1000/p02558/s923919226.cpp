#include <iostream>
#include <cstdio>
#include <cstring>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
template<class T> inline void read(T &x){
    x=0; 
    T f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(ch<='9' && ch>='0'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    x*=f;
}
int n,m;
int main(){
	read(n),read(m);
	dsu d(n);
	int x,y,z;
	for(int i=1;i<=m;i++){
		read(x),read(y),read(z);
		if(x==1){
			if(d.same(y,z)){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		if(x==0){
			d.merge(y,z);
		}
	}
	return 0;
}
