#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int main(void) {
    int a, b, m;
    cin >> a >> b >> m;
    
    vector<int> a_ary;
    vector<int> b_ary;
    
    int m_ary[m][3];
    
    int z = 0;
    for (int i = 0; i < a; i++) {
        cin >> z;
        a_ary.push_back(z);
    }
    
    for (int i = 0; i < b; i++) {
        cin >> z;
        b_ary.push_back(z);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> m_ary[i][j];
        }
    }
    
    vector<int> totals;
    
    totals.push_back(*min_element(a_ary.begin(), a_ary.end()) + *min_element(b_ary.begin(), b_ary.end()));
    
    for (int i = 0; i < m; i++) {
        totals.push_back(a_ary[m_ary[i][0] - 1] + b_ary[m_ary[i][1] - 1] - m_ary[i][2]);
    }
    
    cout << *min_element(totals.begin(), totals.end()) << endl;
    
    return 0;
}