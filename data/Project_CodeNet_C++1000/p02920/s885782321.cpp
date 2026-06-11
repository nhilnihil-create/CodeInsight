#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;

int main(){
    int n;  cin >> n;
    vector<ll> s((1 << n));
    multiset<ll> st;
    for(int i = 0; i < (1 << n); i++){
        cin >> s[i];
        st.insert(s[i]);
    }
    vector<ll> taken;
    auto itr = st.end();
    itr--;
    taken.push_back(*itr);
//    cout << *(itr) << endl;
    st.erase(itr);

    while(st.size() > 0){
        vector<ll> new_taken;
        for(auto v: taken){
            auto itr = st.lower_bound(v);
            if(itr == st.begin()){
                cout << "No" << endl;
                return 0;
            }
            itr--;
            new_taken.push_back(*itr);
            st.erase(itr);
        }

        for(auto v: new_taken){
            taken.push_back(v);
        }
        sort(taken.begin(), taken.end());
    }

    cout << "Yes" << endl;


    return 0;
}
