#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

int N;
Int K;
vector<Int> A;
Int sum = 0;

vector<Int> enumerate_divisor(Int x) {
    vector<Int> d;

    for(Int y = 1;y*y <= x;y++) {
        if(x % y == 0) {
            d.push_back(y);
            if(y*y != x)
                d.push_back(x/y);
        }
    }

    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    
    return d;
}

int main(void) {
    cin>>N>>K;

    for(int i = 0;i < N;i++) {
        Int a;
        cin>>a;
        A.push_back(a);
        sum += a;
    }
    
    for(auto d: enumerate_divisor(sum)) {
        vector<Int> R;
        
        for(auto a: A) {
            R.push_back(a % d);
        }

        sort(R.begin(),R.end());
        Int need = TEN(18);
        Int A = 0;
        Int B = 0;
        for(auto r: R)
            B += (d-r);

        for(int i = 0;i < N;i++) {
            A += R[i];
            B -= (d-R[i]);

            need = min(need,max(A,B));
        }

        if(need <= K) {
            cout<<d<<endl;

            return 0;
        }
    }

    return 0;
}
