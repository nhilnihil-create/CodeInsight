#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> vec_score;

double average(const vec_score &scores);
double stdev(const vec_score &scores);

int main(){
    int n;
    for(cin >> n; n; cin >> n){
        vec_score scores(n, 0);
        for(auto &score : scores){
            cin >> score;
        }
        cout << fixed << setprecision(5) << stdev(scores) << endl;
    }
}

double average(const vec_score &scores){
    double sum = 0;
    for (auto score : scores) sum += score;
    return sum / scores.size();
}

double stdev(const vec_score &scores){
    double mean = average(scores);
    double sse = 0;
    for (auto score : scores) sse += (score - mean) * (score - mean);
    return sqrt(sse / scores.size());
}