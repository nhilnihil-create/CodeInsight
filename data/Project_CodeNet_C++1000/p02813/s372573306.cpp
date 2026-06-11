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

    int N; 
    cin >> N;
    
    int p[N]; 
    int q[N]; 

    int a_num = 0;
    int b_num = 0;

    vector<int> nums;

    vector<string> for_sort;

    string p_str;
    for (int i = 0; i < N ; i++) {
        cin >> p[i];
        p_str += to_string(p[i]);

        nums.push_back(i+1);

    }

    string q_str;
    for (int i = 0; i < N ; i++) {
        cin >> q[i];
        q_str += to_string(q[i]);

    }

    

    // vector順列ループ
    do {

        string num_str = "";
        for (int i = 0; i < nums.size() ; i++) {

            //cout << "nums.at(i) "<< nums.at(i) << endl;

            num_str =  num_str + to_string(nums.at(i));
        }
        //cout << "-------- num_str "<< num_str << endl;
        for_sort.push_back(num_str);
   

        //printVector(nums);
    } while (next_permutation(nums.begin(), nums.end()));


    sort(for_sort.begin(), for_sort.end());

    //cout << "p_str: "<< p_str << endl;
    //cout << "q_str: "<< q_str << endl;

    for (int i = 0; i < for_sort.size() ; i++) {

        //cout << for_sort.at(i) << endl;

        if (p_str == for_sort.at(i)){
            a_num = i;
        }

        if (q_str == for_sort.at(i)){
             b_num = i;
        }
    }

    cout << abs(a_num - b_num)<< endl;


    return 0;

}