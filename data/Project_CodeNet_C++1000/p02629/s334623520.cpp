#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;
using posteriority_queue = priority_queue<int, vi, greater<int>>;


int main() {
    ll N; cin >> N;
    int a_kind = 'a'-1;
    vll A(15,0), exp_26(15,1);
    char tmp_char;
    vll tmp_div(15), tmp_mod(15);
    for (int i = 0; i  < 15; i++) {
        if(N <= 26) {
            tmp_mod.at(i)=N;
            for (int j = i; j >=0; j--) {
                tmp_char = a_kind + tmp_mod.at(j);
                cout << tmp_char;
            }
            break;
        }
        tmp_div.at(i)=N/26;
        tmp_mod.at(i)=N%26;
        if(tmp_mod.at(i)==0) {
            tmp_mod.at(i)=26;
            N = tmp_div.at(i)-1;
        } else {
            N = tmp_div.at(i);
        }
    }
}
