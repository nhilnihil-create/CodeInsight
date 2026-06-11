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

const int max_n = 300000+10;
int N;

int main(void) {
    cin>>N;
    vector<int> A(N);

    for(int i = 0;i < N;i++) {
        int a;
        cin>>a;
        A[a-1]++;
    }

    sort(A.begin(),A.end());
    vector<int> s(N+1);
    for(int i = 0;i < N;i++) {
        s[i+1] = s[i]+A[i];
    }

    for(int k = 1;k <= N;k++) {
        int left = 0;
        int right = N/k+1; //[l,r)
        while(left<right-1) {
            int mid = (left+right)/2;
            bool ok = [&](int mid) {
                int l = lower_bound(A.begin(),A.end(),mid)-A.begin();
                int ans = mid*(N-l) + s[l];

                return (ans >= mid*k);
            }(mid);

            if(ok) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout<<left<<endl;
    }

    return 0;
}
        



