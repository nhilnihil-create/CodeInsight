#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int main()
{
	int a,b;
  	cin>>a>>b;
  	if(2*b > a){
    	printf("0");
    }
 	else{
    	printf("%d",a-2*b);
    }
    return 0;
}
