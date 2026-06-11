#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;

int main(){
    string s, t;
    cin >> s;
    cin >> t;

    vector<set<int>> char_trees(26);
    vector<int> min_indices(26, 0);

    for(int i = 0; i < s.size(); ++i){
        int index = s[i] - 'a';
        char_trees[index].insert(i+1);
        if(min_indices[index] == 0){
            min_indices[index] = i + 1;
        }
    }

    long long num_loop = 0;
    int cur_pos = 0;
    for(int i = 0; i < t.size(); ++i){
        int index = t[i] - 'a';

        if(min_indices[index] == 0){
            cout << -1;
            return 0;
        }

        auto it = char_trees[index].upper_bound(cur_pos);
        if(it != char_trees[index].end()){
            cur_pos = *it;
        }
        else{
            cur_pos = min_indices[index];
            ++num_loop;
        }
    }

    cout << num_loop * s.size() + cur_pos;

}
