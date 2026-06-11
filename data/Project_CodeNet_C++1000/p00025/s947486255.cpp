#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a[4];
	int b[4];
	int hit,blow;

	while(scanf("%d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&b[0],&b[1],&b[2],&b[3]) != EOF){
		hit = 0;
		blow = 0;
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 4;j++){
				if(a[i] == b[j] && i == j){
					hit++;
				}
				if(a[i] == b[j] && j != i){
					blow++;
				}
			}
		}
		cout << hit << " " << blow << endl;
	}
}