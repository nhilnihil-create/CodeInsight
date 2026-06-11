#include <bits/stdc++.h>
using namespace std;
long long   gcd(long long a,long long b)
{
	if(b==0)return a;
	gcd(b,a%b);
}
int main()
{
	long long a,b;
	cin>>a>>b;
	 //cout<<a/gcd(a,b)*b<<endl;
	 for(int i = 1; i <= b; i++){
    if((a* i) % b == 0){
      cout << a * i << endl;
      break;
    }
  }
return 0;
}
