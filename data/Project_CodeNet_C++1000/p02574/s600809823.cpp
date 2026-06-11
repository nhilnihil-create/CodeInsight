
#include<bits/stdc++.h>


using namespace std;

using ll   = long long;
using ii   = pair   < int , int >;
using i3   = pair   < int , ii  >;
using li   = pair   < ll  , int >;
using lii  = pair   < ll  , ii  >;
using pll  = pair   < ll  , ll  >;
using vi   = vector < int       >;
using vl   = vector < ll        >;
using vii  = vector < ii        >;
using vli  = vector < li        >;
using vpll = vector < pll       >;
using vi3  = vector < i3        >;
using vlii = vector < lii       >;


const int N = 2e6 + 5;
const ll INF = 1e17 + 7;
const double eps = 1e-9 , PI = acos(-1);


int n , m;

int spf[N];
bool prime[N];

void seive() {

    prime[0] = prime[1] = 1;

    for(ll i = 2 ; i < N ; i ++) {
            if(!prime[i]) {
                    spf[i] = i;
                    for(ll j = i*i ; j < N ; j += i) {
                            spf[j] = i;
                            prime[j] = 1;
                    }
            }
    }
}

map < int , int > freq;

void work(int x) {

    if(x == 1) return;

    while(x > 1) {
            int curr = spf[x];

            freq[curr] ++;

            while(x%curr == 0) x /= curr;
    }

    if(x > 1) {
            freq[x] ++;
    }
}

bool check(int x) {

    if(x == 1) return false;

    while(x > 1) {
            int curr = spf[x];

            if(freq[curr] > 1) return true;
            while(x%curr == 0) x /= curr;
    }

    if(x > 1) {
            if(freq[x] > 1) return true;
            freq[x] ++;
    }

    return false;
}


void solve(int testCase){

    scanf("%d" , &n);

    seive();

    vector < int > a(n);

    int g = 0;
    for(int i = 0 ; i < n ; i ++) {
            scanf("%d" , &a[i]);
            work(a[i]);

            g = __gcd(g , a[i]);
    }

    if(g > 1) {
            printf("not coprime\n");
            return;
    }

    for(int i = 0 ; i < n ; i ++) {
            if(check(a[i])) {
                    printf("setwise coprime\n");
                    return;
            }
    }

    printf("pairwise coprime\n");


}

main(){

    int t = 1;
    // scanf("%d" , &t);

    for(int testCase = 1 ; testCase <= t ; testCase ++){
            solve(testCase);
    }

    return 0;
}
