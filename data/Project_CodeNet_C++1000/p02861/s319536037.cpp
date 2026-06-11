#include <bits/stdc++.h>
using namespace std;



int main(){
    int N;
    cin >> N;
    vector<tuple<int, int>> xy;
    int x_i, y_i;
    tuple<int, int> data;
    for (int i = 0; i < N; i++){
        cin >> x_i >> y_i;
        data = make_tuple(x_i, y_i);
        xy.push_back(data);
    }
    long double distance_sum = 0;
    sort(xy.begin(), xy.end());
    do {
        int now_x, now_y;
        int tar_x, tar_y;
        now_x = get<0>(xy.at(0));
        now_y = get<1>(xy.at(0));
        for (auto xy_i: xy){
            tar_x = get<0>(xy_i);
            tar_y = get<1>(xy_i);
            distance_sum += sqrt(pow((now_x - tar_x), 2) + pow((now_y - tar_y), 2));
        }
    }while(next_permutation(xy.begin(), xy.end()));
    int num_route = 1;
    for(int i = 1; i <= N; i++){
        num_route *= i;
    }
    cout << fixed << setprecision(15) << distance_sum / num_route << endl;
}