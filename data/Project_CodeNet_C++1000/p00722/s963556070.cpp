#include<iostream>
#include<cmath>
#define MAX 1000000
using namespace std;
bool array[MAX];
void era(){
	array[1] = false;
	for(int i=2;i<MAX;i++)	array[i]=true;
	for(int i=2;i<sqrt(MAX);i++){
		if(array[i]){
			for(int j=i*2;j<MAX;j+=i){
				array[j]=false;
			}
		}
	}
}

 
int main(){
	era();
	while(1){
		int a,d,n,cnt=0;
		cin >> a >> d >> n;
		if(!a&&!d&&!n)	break;
		for(int i=a;;i+=d){
			if(array[i]){
					cnt++;
					if(cnt==n){
							cout << i << endl;
							break;
					}
			}
		}
	}
}
