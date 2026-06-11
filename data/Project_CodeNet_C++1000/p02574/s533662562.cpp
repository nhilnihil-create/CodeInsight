#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,a,f;
int t[N],maxn=-N;
void hs(int x){
    for(int i=2;i<=sqrt(x);){
        if(x%i==0){
            t[i]++;
            while(x%i==0) x/=i;
        }
        else i++;
    }
    if(x>1) t[x]++;
}
int main(){
    scanf("%d%d",&n,&a);
    f=a;
    for(int i=2;i<=n;i++){
		scanf("%d",&a);
        if(maxn<a) maxn=a;
        f=__gcd(f,a);
        hs(a);
    }
    if(f==1){
        for(int i=2;i<=maxn;i++){
        	if(t[i]>1){
				printf("setwise coprime\n");
				return 0;
			}
		}
        printf("pairwise coprime\n");
        return 0;
    }
    else{
    	printf("not coprime\n");
    	return 0;
	}
    return 0;
}