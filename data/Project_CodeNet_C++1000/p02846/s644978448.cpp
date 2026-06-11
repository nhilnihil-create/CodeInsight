#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    long T1, T2, A1, A2, B1, B2;
    cin>>T1>>T2 >> A1 >> A2 >> B1 >> B2;
    long rel_A1 = A1 - B1, rel_A2 = A2 - B2;
    if(T1 * rel_A1 + T2 * rel_A2 == 0){
        cout << "infinity" << endl;
        return 0;
    }else{
        long d = T1 * rel_A1 + T2 * rel_A2;
        if(!((rel_A1 > 0) ^ (d > 0))){
            cout << 0 << endl;
            return 0;
        }else{
            d = (d < 0) ? -d : d;
            long l = (T1 * rel_A1 > 0) ? T1 * rel_A1 : -T1 * rel_A1;
            long count = (l/ d) * 2 + 1;
            if(l % d == 0) count--;
            cout << count << endl;
        }
    }
    return 0;

}