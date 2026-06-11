#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    bool ans = false;

    vector<vector<int> > A(3,vector<int>(3));
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin >> A.at(i).at(j);
        }
        
    }

    int N = 0;
    cin >> N;
    vector<int> l(N,0);
    for(int i = 0; i < N; i++) {
    cin >> l.at(i);
    for (size_t j = 0; j < 3; j++)
    {
        for (size_t k = 0; k < 3; k++)
        {
            if (A.at(k).at(j) == l.at(i))
            {
                A.at(k).at(j) = 0;
            }
            
        }
        
    }
    
    }
    for (size_t i = 0; i < 3; i++)
    {
        if(A.at(0).at(i) == A.at(1).at(i) && A.at(2).at(i) == A.at(1).at(i))ans = true;
        if(A.at(i).at(0) == A.at(i).at(1) && A.at(i).at(1) == A.at(i).at(2))ans = true;
    }
    
    if(A.at(0).at(0) == A.at(1).at(1) && A.at(2).at(2) == A.at(1).at(1))ans = true;
    if(A.at(0).at(2) == A.at(1).at(1) && A.at(2).at(0) == A.at(1).at(1))ans = true;

    


    
    

    if(ans) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }

    return 0;
}