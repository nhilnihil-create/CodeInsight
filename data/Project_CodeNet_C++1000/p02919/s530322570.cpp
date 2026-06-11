#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    vector<int> ind(N);
    for(int i = 0; i < N; i++) ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int x, int y){
        return P[x] > P[y];
    });
    set<int> s;
    long long ans = 0;
    s.insert(-1);
    s.insert(N);
    s.insert(ind[0]);
    for(int i = 1; i < N; i++){
        auto ite = s.upper_bound(ind[i]);
        long long r = ind[i], l = ind[i];
        auto ite2 = ite, ite3 = ite, ite4 = ite;
        long long res = 0;
        if(*ite == N){
            r = N - ind[i];
            ite--;
            long long temp = *ite;
            ite--;
            l = temp - *ite;
            res += l * r;
        }
        else if(*(--ite4) == -1){
            l = ind[i] + 1;
            long long temp = *ite2;
            ite2++;
            r = *ite2 - temp;
            res += r * l;
        }
        else{
            long long temp1 = *ite, temp2 = *(++ite2), temp3 = *(--ite3);
            res += (ind[i] - temp3) * (temp2 - temp1);
            if(temp3 != -1){
                long long temp4 = *(--ite3);
                res += (temp3 - temp4) * (temp1 - ind[i]);
            }
        }
        s.insert(ind[i]);
        ans += res * P[ind[i]];
    }
    cout << ans << endl;
}