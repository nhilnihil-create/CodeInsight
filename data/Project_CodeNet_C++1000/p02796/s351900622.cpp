#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<long long, long long>> vec(N);
    //入力
    for(int i=0; i<N; i++){
        long long place, change;
        cin >> place >> change;

        long long max, min;

        max = place + change;
        min = place - change;

        vec[i] = make_pair(max, min);
    }

    //sort関数でmaxが小さい順にソートする
    sort(vec.begin(), vec.end());

    int count = 0;
    long long just_max = 0;
    //maxが小さい順に、既に選択されたものと被っていなければcountをプラスする
    for(int i=0; i<N; i++){
        if(just_max <= vec[i].second || i==0){//被っていないか確認する
            count++;
            just_max = vec[i].first;
        }
    }

    cout << count << endl;
}