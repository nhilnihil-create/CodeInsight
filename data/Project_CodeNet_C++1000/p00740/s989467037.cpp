#include <iostream>
#include <cstdio>
using namespace std;
#define N 50
int i,n,p,tmp;
int ca[N];
bool sen(int tmp){
	int ans = 0;
	for(int i=0;i<n;i++){
		if(ca[i]==tmp) ans++;
	}
	if(ans) return false;
	else return true;
}

int main(){
	while(cin >> n >> p){
	//cin >> n >> p;	
		if(n==0&&p==0) break;
		tmp = p;
		for(i=0;i<n;i++) ca[i]=0;
		
		int k,j = 0;
		while(sen(tmp)){
			k = j%n;
			if(p==0){
				p += ca[k];
				ca[k] = 0;
			}else{
				p -= 1;
				ca[k]++;
			}
			j++;
		}
	    for(i=0;i<n;i++){
	    	if(ca[i]==tmp) cout << i <<endl;
		}
	}
	return 0;
}