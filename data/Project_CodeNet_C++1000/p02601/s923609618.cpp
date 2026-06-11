#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for(int i=a; i<b; i++)
#define mem(arr, val) memset(arr, val, sizeof(arr))

#define MOD 1000000007
#define INF 1000000001
#define epsilon 1e-15

typedef long long int ll;
typedef unsigned long long int ull;

/*int seive(int N){
    bool primes[N+1];
    int cnt=0;
    mem(primes, true); primes[1] = false;
    int m = sqrt(N);
    for(int i=2; i<=m; i++){
        if(primes[i]){
            for(int p = i*i; p<=N; p+=i)
                primes[p] = false;
        }
    }

    for(int i=2; i<=N; i++){
        if(primes[i])
            cnt++;
    }

    return cnt;
} */

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}


   
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int A, B, C, K, ops=0;
    cin >> A >> B >> C >> K;
    while(B<=A){
        B *= 2;
        ops++;
    }

    while(C<=B){
        C *= 2;
        ops++;
    }

    if(ops > K) cout << "No\n";
    else cout << "Yes\n";

    return 0;
   
}