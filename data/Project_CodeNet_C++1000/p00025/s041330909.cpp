#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	int a[3],b[3],dat=1;

	while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])!=EOF){
		int h=0,n=0;

		for(int j=0;j<4;j++){
			cin>>dat;
			b[j]=dat;
	}
	for(int k=0;k<4;k++){
			if(a[k]==b[k]){
				h++;
			}

		for(int o=0;o<4;o++){
			if(a[k]!=b[k] && a[k]==b[o]){
				n++;
			}
		}
	}
	cout<<h<<" "<<n<<endl;
	}
	return 0;
}	