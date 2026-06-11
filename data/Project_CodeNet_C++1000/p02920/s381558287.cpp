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

int main(void) {
    int n;
    cin>>n;
    int n2 = 1<<n;
    vector<int> A(n2);
    for(int i = 0;i < n2;i++) {
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    vector<int> s;
    s.push_back(A.back());
    A.back() = -1;
    for(int i = 0;i < n;i++) {
        vector<int> p = s;
        sort(p.begin(),p.end());
        int ai = n2-1;
        while(p.size() > 0 && ai >= 0) {
            if(A[ai] == -1) {
                ai--;
                continue;
            }
            if(A[ai] < p.back()) {
                s.push_back(A[ai]);
                p.pop_back();
                A[ai] = -1;
            }
            --ai;
        }
        if(p.size() > 0) {
            cout<<"No"<<endl;

            return 0;
        }
    }

    cout<<"Yes"<<endl;


    return 0;
}
