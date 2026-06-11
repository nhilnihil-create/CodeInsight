#include<iomanip>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

//vector<vector<int>> perm(vector<int> head, vector<int> rest);
double sq(double x);

int main(){
    long long N;
    double X, Y, d;
    double pair_ = 1.0;
    double d_total = 0.0;
    double ans;
    std::cin >> N;
    vector<vector<double>> matchi_list(N);

    for(long long i = 0; i < N; i++){
        std::cin >> X >>Y;
        matchi_list[i] = {X, Y}; 
    }

    for(long long i = 0; i < N; i++ ){
        for(long long j = i + 1; j < N; j ++){
            d = sqrtf(sq(matchi_list[i][0] - matchi_list[j][0]) + sq(matchi_list[i][1] - matchi_list[j][1]));
            d_total = d_total + d;
        }
    }

    ans = d_total * 2.0 / (double)N;
    // vector<int> v_in = {1,2,3,4,5,6,7,8,};
    // vector<vector<int>> v_out = perm({}, v_in);

    // for(int i = 0; i < v_out.size(); i++){
    //     for(int j = 0; j < v_out[0].size(); j++){
    //         std::cout << v_out[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    std::cout << setprecision(16) << ans;

}

// vector<vector<int>> perm(vector<int> head, vector<int> rest){
//     vector<vector<int>> v_out;
//     vector<vector<int>> v_temp;
//     int count = 0;
//     if(rest.size() == 0){
//         v_out.push_back(head);
//     }
//     vector<int> restx;
//     vector<int> headx;
//     std::vector<int>::iterator iter;
//     for(int i = 0; i < rest.size(); i++){
    
//         restx = rest;
//         headx = head;
//         iter = restx.begin();
//         for(int j = 0; j < count; j ++){
//             iter++;
//         }
//         headx.push_back(*iter);
//         restx.erase(iter);
//         restx.shrink_to_fit();
//         v_temp = perm(headx, restx);
//         v_out.insert(v_out.begin(), v_temp.begin(), v_temp.end()) ;
//         count++;
 
//         restx.clear();
//         headx.clear();

//     }

//     return v_out;
// }

double sq(double x){
     double ans;
     ans = x * x;
     return ans;
}