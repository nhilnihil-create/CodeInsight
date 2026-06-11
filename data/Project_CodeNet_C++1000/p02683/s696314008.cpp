#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    cout << "print_vector -> ";
    for(int i=0; i<vec.size(); i++) {
        if(i == vec.size()-1) {
            cout << vec[i] << endl;
        }
        else {
            cout << vec[i] << " ";
        }
    }
    return;
}

typedef struct {
    int c;
    vector<int> A;
} Data;

int N, M, X;

void bnf(vector<int> conv, vector<Data> data, unsigned long long *ans) {

    if(conv.size() > N) return;

    unsigned long long temp_ans = 0;
    vector<int> sum(M, 0);
    for(int i=0; i<conv.size(); i++) {
        for(int j=0; j<M; j++) {
            sum[j] += data[conv[i]].A[j];
        }
        temp_ans += data[conv[i]].c;
    }

    bool p = true;
    for(int i=0; i<M; i++) {
        if(sum[i] < X) {
            p = false;
        }
    }

    if(p && temp_ans < *ans) {
        *ans = temp_ans;
    }

}

int main() {

    cin >> N >> M >> X;

    vector<Data> data(N);

    for(int i=0; i<N; i++) {
        cin >> data[i].c;
        for(int j=0; j<M; j++) {
            int temp;
            cin >> temp;
            data[i].A.push_back(temp);
        }
    }
    
    unsigned long long ans = 10E+12;
    int bit = 0;
    for(int i=0; i<N; i++) {
        bit |= (1 << i);
    }
    for(int i=0; i<=bit; i++) {
        vector<int> conv;
        for(int j=0; j<N; j++) {
            if((i >> j) & 0x01 == 0x01) {
                conv.push_back(j);
            } 
        }
        bnf(conv, data, &ans);
    }

    if(ans == 10E+12) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}