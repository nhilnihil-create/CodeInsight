#include<iostream>
#include<algorithm>
#define maxn 200005
using namespace std;
typedef long long ll;
int a[maxn];
int main(){
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i];
       
       ll ans  =0;
       for(int i=2;i<=n;i++){
       	if(a[i] < a[i-1]){
       		ans += a[i-1] -a[i];
       		a[i] = a[i-1];
		   }
	   }
	   cout<<ans<<endl;
}