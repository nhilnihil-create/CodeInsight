#include <iostream>
#define N 1000005
using namespace std;
typedef long long ll;

ll n;
ll M=1e9+7, fac[N]={1,1}, inv[N]={1,1}, fiv[N]={1,1};

int main(void)
{
    int x,y;
    cin >> x >> y;
    int p=(2*x-y)/3;
    int q=(2*y-x)/3;
    if((x+y)%3!=0 || p<0 || q<0)
    {
        cout << 0;
        return 0;
    }
    for(int i=2; i<=N; i++) {
		fac[i] = fac[i-1] * i % M;
		inv[i] = inv[M%i] * (M-M/i) % M;
		fiv[i] = fiv[i-1] * inv[i] % M;
	}
	cout << fac[p+q]*fiv[p]%M*fiv[q]%M;
    return 0;
}
