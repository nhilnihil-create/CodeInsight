#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    for(int i=0;i<n;i++){
    	if(a>=b)b=b*2;
    	else if(b>=c)c=c*2;
	}
    if(a<b&&b<c)cout<<"Yes";
    else cout<<"No";
    
    
    return 0;
}
