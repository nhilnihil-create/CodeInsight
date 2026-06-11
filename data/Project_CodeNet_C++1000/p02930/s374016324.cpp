#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int ans[500][500];

void func(int level, vector<int>& v){

    if((int)v.size() <= 1){
        return;
    }

    if((int)v.size() == 2){
        ans[v[0]][v[1]] = level;
        return;
    }

    vector<int> l;
    vector<int> r;

    for(int i = 0; i < (int)v.size(); i++){
        if(i % 2 == 0){
            l.push_back(v[i]);
            for(int j = 0; j < (int)v.size(); j++){
                if(j % 2 == 1){
                    int big = max(v[i], v[j]);
                    int small = min(v[i], v[j]);
                    ans[small][big] = level;
                }
            }
            
        }
        else{
            r.push_back(v[i]);
        }
    }

    func(level + 1, l);
    func(level + 1, r);

}

int main(){

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++){
        v[i] = i;
    }

    func(1, v);

    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            cout << ans[i][j];
            if(j == N - 1){
                cout << endl;
            }
            else{
                cout << " ";
            }
        }
    }

    return 0;
}