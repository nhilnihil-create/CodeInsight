#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b)/gcd
std::vector<int> v;
/***bool ar[1005];
void sieve(){
	for(int i=0;i<=1005;i++){
	  ar[i]=true;
	}
	ar[0]=false;
	ar[1]=false;
	for(int i=4;i<=1005;i+=2){
		ar[i]=false;
	}
	for(int i=3;i<=1005;i+=2){
		if(ar[i]==true){
			for(int j=i*i;j<=1005;j+=i){
				ar[j]=false;
			}
		}
	}
}
****/

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
   string s;
   cin>>s;
   for(int i=0;i<3;i++) cout<<s[i];
   cout<<endl;
   return 0;

}
