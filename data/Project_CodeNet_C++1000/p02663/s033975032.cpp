#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    int h_1, m_1, h_2, m_2 , k;
    cin >> h_1 >> m_1 >> h_2 >> m_2 >> k;
    
    int h;
    h = (h_2 - h_1) * 60;
    
    cout << h + (m_2 - m_1) - k << endl;
}