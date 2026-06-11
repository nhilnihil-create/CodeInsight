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
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i = 0;i < N;i++) {
        cin>>A[i];
        A[i]--;
    }
    vector<int> idx(N);
    for(int i = 0;i < N;i++) {
        idx[A[i]] = i;
    }
    set<int> s;
    Int ans = 0;
    for(int x = N-1;x >= 0;x--) {
        int i = idx[x];
        Int c = 0;
        
        { //calc c
            s.insert(i);
            vector<Int> L(2,-1);
            vector<Int> R(2,N);
            {
                auto it = s.find(i);
                for(int j = 0;j < 2;j++) {
                    if(it == s.begin())
                        break;
                    --it;
                    L[j] = *it;
                }
            }
            {
                auto it = s.find(i);
                for(int j = 0;j < 2;j++) {
                    it++;
                    if(it == s.end())
                        break;
                    
                    R[j] = *it;
                }
            }

            vector<Int> ls(2);
            ls[0] = i-L[0]; ls[1] = L[0] - L[1];
            vector<Int> rs(2);
            rs[0] = R[0] - i; rs[1] = R[1]-R[0];
            
            c = ls[0]*rs[1] + ls[1]*rs[0];
        }

        ans += c*(x+1);
    }

    cout<<ans<<endl;


    return 0;
}
