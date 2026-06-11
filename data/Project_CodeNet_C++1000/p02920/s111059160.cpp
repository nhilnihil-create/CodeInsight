#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }


int main(){
    int N;
    cin >> N;
    vector<int> S(1<<N);
    REP(i, (1<<N)) cin >> S[i];
    sort(S.begin(), S.end(), greater<int>());

    multiset<int> A, B;
    A.insert(S[0]);
    REP(i, 1, (1<<N)) B.insert(S[i]);
    while(!B.empty()){
        auto AA = A;
        for(auto itr=AA.rbegin(); itr!=AA.rend(); itr++){
            int a = *itr;
            auto itr2 = B.lower_bound(a);
            if(itr2==B.begin()){
                cout << "No" << endl;
                return 0;
            }
            itr2--;
            A.insert(*itr2);
            B.erase(itr2);
        }
    }
    cout << "Yes" << endl;
    return 0;
}