#include <iostream>
#include <cstdlib>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
    string S;cin>>S;
    char before = S[0];
    ll cur = 0;
    vector<ll> vc;
    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        if (c == '<' && c == before) cur++;
        else if (c == '<' && c != before) {
            vc.push_back(cur); 
            cur = 1;

        } else if (c == '>' && c == before) cur--;
        else if (c == '>' && c != before) {
            vc.push_back(cur);
            cur = -1;
        }
        before = c;
    }
    vc.push_back(cur);

    ll vc_before = vc[0];
    for (int i = 1; i < vc.size(); i++) {
        
        ll int_vc = vc[i];
        if (vc_before > 0 && int_vc < 0) {
            if (vc_before < abs(int_vc)) vc[i-1] -= 1;
            else vc[i] += 1;
        }
        vc_before = vc[i];
    }
    ll result = 0;
    for (auto int_vc:vc) {
        result += abs(int_vc) * (abs(int_vc) + 1) / 2;
    }
    cout << result << endl;
    return 0;
}