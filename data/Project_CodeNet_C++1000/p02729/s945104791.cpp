#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int n_ans = 0;
    int m_ans = 0;
    if(n>1){
        n_ans++;
        n_ans *= n*(n-1);
        n_ans /= 2;
    }

    if(m>1){
        m_ans++;
        m_ans *= m*(m-1);
        m_ans /= 2;
    }

    cout << n_ans + m_ans << endl;
}