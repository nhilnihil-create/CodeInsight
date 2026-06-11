#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;


int main() {
    int N;
    cin >> N;
    vector<int> data;
    int pl = 0;
    int mn = 0;
    vector<int> pls, mns;

    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        if(a>0)
            pls.push_back(a);
        else
            mns.push_back(a);
    }
    sort(mns.begin(), mns.end());
    sort(pls.begin(), pls.end());
    reverse(pls.begin(), pls.end());
    if(pls.size() == 0) {
        int k = mns.back();
        mns.pop_back();
        pls.push_back(k);
    }
    if(mns.size() == 0) {
        int k = pls.back();
        pls.pop_back();
        mns.push_back(k);
    }

    vector<PII> output;

    while(pls.size() >= 2) {
        int k = mns.back();
        mns.pop_back();
        int j = pls.back();
        pls.pop_back();
        output.push_back(PII(k, j));
        k -= j;
        mns.push_back(k);
    }
    while(mns.size() >= 1) {
        int k = pls.back();
        pls.pop_back();
        int j = mns.back();
        mns.pop_back();
        output.push_back(PII(k, j));
        k -= j;
        pls.push_back(k);

    }
    cout << pls[0] << endl;
    for(auto elem: output) {
        int a = elem.first;
        int b = elem.second;
        cout << a << " " << b << endl;
 
    }


    return 0;
} 