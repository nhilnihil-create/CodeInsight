#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>S(m);
    vector<int>C(m);
    for (int i=0; i<m; i++) cin >> S[i] >> C[i];
    for (int i=0; i<1000; i++){
        string st = to_string(i);
        bool jud = true;
        if (st.size() != n) jud = false;
        for (int j=0; j<m; j++){
            if (st[S[j]-1] != (char)(C[j]+'0')) jud = false;
        }
        if (jud){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}