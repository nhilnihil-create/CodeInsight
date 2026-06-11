#include<cstdio>
#include<cstdlib>
using namespace std;
int x,now;
int main() {
	scanf("%d",&x);
	for(int ii=1;;++ii) {
		now+=x;
		if(now%360==0) {printf("%d",ii);break;}
	}
	return 0;
}