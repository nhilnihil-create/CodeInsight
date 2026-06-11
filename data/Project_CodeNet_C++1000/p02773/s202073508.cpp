#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string,int> S;

    for(int i=0; i<N; i++){
        string s; cin >> s;
        if(S.count(s)){
            S.at(s)++;
        }else{
            S[s] = 1;
        }
    }

    int m=0;
    for(auto p : S){
        auto v = p.second;
        if(v > m){
            m = v;
        }
    }
    for(auto p :S){
        auto k = p.first;
        auto v = p.second;
        if(v == m)
            cout << k << endl;
    }

}