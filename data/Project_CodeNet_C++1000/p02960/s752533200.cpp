#include <stdio.h>
#include <vector>
using namespace std;

const long long mod = 1000000007;

vector<long long> mul(vector<long long> &a, vector<long long> &b)
{
	vector<long long> r(13);
  for (int i=0;i<13;i++) for (int j=0;j<13;j++){
r[(i+j)%13] = (r[(i+j)%13] + a[i]*b[j]) % mod;
  }
  return r;
}

char S[100100];
int main()
{
  scanf ("%s",S);
  int n = 0;
  while (S[n]) n++;
  long long u = 1;
  vector<long long> a(13); a[0] = 1;
  for (int i=n-1;i>=0;i--){
    vector<long long> b(13);
    if (S[i] == '?'){
for (int i=0;i<10;i++) b[(i*u)%13] = 1;
    }
    else{
b[(S[i]-'0')*u%13] = 1;
    }
    a = mul(a,b);
u = u * 10; u %= 13;
  }
  printf ("%lld\n",a[5]);
return 0;
}