#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int i=1;
    vector<pair<int, int>> res;
    for(; i<N-1; i++){
        if(A.at(i) > 0) break;
        res.emplace_back(A.back(), A.at(i));
        A.back() -= A.at(i);
    }
    for(; i<N-1; i++){
        res.emplace_back(A.front(), A.at(i));
        A.front() -= A.at(i);
    }
    res.emplace_back(A.back(), A.front());

    cout << (res.back().first - res.back().second) << endl;
    for(auto v : res){
        cout << v.first << " " << v.second << endl;
    }

    return 0;
}