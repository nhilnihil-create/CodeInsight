#include <iostream>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int a,b,c,k,sum=0;
	
	cin>>a>>b>>c>>k;
    sum+=min(a,k);
    k-=min(a,k);
    k-=min(k,b);
    sum-=min(c,k);
	cout<<sum;
	return 0;
}