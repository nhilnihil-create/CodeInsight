#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<numeric>

using namespace std;

int main(){ 
    int n, m;
    vector<int> vec;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        vec.push_back(v);
    }    

    int ct = 0;

    int sum = accumulate(vec.begin(),vec.end(),0);

    for(int i = 0; i < n; i++){
        if(vec[i] * 4 * m >= sum ) ct++;
    }

    if(ct >= m) cout << "Yes" << endl;
    else cout << "No" << endl;

}
