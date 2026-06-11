#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int main(){
	int m,d;
	scanf("%d%d",&m,&d);
	int ans=0;
	for(int d1=2;d1<=9;d1++){
		for(int d10=2;d10<=9;d10++){
			if(d1*d10<=m && d10*10+d1<=d){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	
}
