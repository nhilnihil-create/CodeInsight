#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    long long N, K, ans, i;
  	cin >> N >> K;
    ans = 0;
    
    for(i=K; i<=N+1; i++){
        ans = (ans - i*i +(N+1)*i + 1)%1000000007;
    }
    cout << ans;
}