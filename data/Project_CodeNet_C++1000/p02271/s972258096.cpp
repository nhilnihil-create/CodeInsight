#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 1000

int dat[MAX];
int ind[MAX];
int dp[21][1000];
int n;

bool solve(int i,int m){
    //cout<<"solve i:"<<i<<" m:"<<m<<" n:"<<n<<endl;
    if(m==0){
        return true;
    }else if(i<n){
        if(solve(i+1,m))
	    return true;
        return solve(i+1,m-dat[i]);
    }
    return false;
}

int main(){
    int m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
	scanf("%d",&dat[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
	scanf("%d",&ind[i]);
    }
    for(int i=0;i<m;i++){
        if(solve(0,ind[i])){
	    printf("yes\n");
        }else{
	    printf("no\n");
        }
    }
    return 0;
}