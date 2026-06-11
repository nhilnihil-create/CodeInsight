#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

//https://blog.foresta.me/posts/enumerate_all_pattern/
//https://hacknote.jp/archives/20862/

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int make_kaijo(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

int main() {

    int N; // 街の数、街座標(x, y) // 2 8
    // 、N!通りの、処理の平均値

    cin >> N;

    int x[N]; // -1000 1000
    int y[N]; // -1000 1000

    //vector<int> nums { 0, 1, 2};
    vector<int> nums;

    int kaijo = make_kaijo(N);

    for (int i = 0; i < N ; i++) {
        cin >> x[i] >> y[i];
        nums.push_back(i);

    }

    double total_l = 0;

    // vector順列ループ
    do {
        double l = 0;

        // 一経路あたり
        for (int i = 0; i < N - 1 ; i++) {

            int now = nums.at(i);
            int next = nums.at(i+ 1);
            //cout << "now:  " << now << endl;
            //cout << "next: " << next << endl;

            l +=  sqrt((pow((x[now] - x[next]),2) + pow((y[now] - y[next]),2)));
            //cout << l << endl;
        }
        //cout << "------- l:  " << l << endl;

        total_l += l;

        //printVector(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    
    cout << fixed << setprecision(20) << total_l / kaijo << endl;

    return 0;

}