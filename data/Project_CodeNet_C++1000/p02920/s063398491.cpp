#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> S(1<<N);
    map<int,int> m;
    for(int i=0;i<(1<<N);i++){
        cin >> S[i];
        m[S[i]]++;
    }
    sort(S.begin(),S.end(),greater<int>());

    auto decrement = [&](int value){
        m[value]--;
        if(m[value]==0) m.erase(value);
    };
    vector<int> exist;
    exist.push_back(S[0]);
    decrement(S[0]);
    for(int i=0;i<N;i++){
        sort(exist.begin(),exist.end(),greater<int>());
        vector<int> nexist = exist; 
        for(auto x:exist){
            map<int,int>::iterator it = m.lower_bound(x);
            if(it==m.begin()){
                cout << "No" << endl;
                return 0;
            }
            it--;
            nexist.push_back(it->first);
            decrement(it->first);
        }
        exist = nexist;
    }
    cout << "Yes" << endl;
}