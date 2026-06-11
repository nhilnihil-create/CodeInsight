#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200090;

ll n,k,ab;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
    n = read(), k = read();
    ab=n%k; 

	if(ab>abs(ab-k)){
		ab=abs(ab-k);
	}

	printf("%lld\n",ab);

	return 0;
}