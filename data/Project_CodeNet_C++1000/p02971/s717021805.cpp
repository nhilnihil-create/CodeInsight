#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    typedef pair<int, int> vals;
    priority_queue<vals> que;
    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        vals tmp_val = make_pair(tmp, i);
        que.push(tmp_val);
    }

    vals max_val = que.top();
    int max_value = max_val.first;
    int max_index = max_val.second;
    que.pop();
    max_val = que.top();
    int second_max_value = max_val.first;

    for(int i=0; i<N; i++){
        if(i==max_index){
            cout << second_max_value << "\n";
        }else{
            cout << max_value << "\n";
        }
    }

    return 0;

}