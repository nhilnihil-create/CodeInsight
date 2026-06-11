#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
vector<int> x(10), y(10);

double distance(int i, int j){
    double dx = x.at(i) - x.at(j);
    double dy = y.at(i) - y.at(j);
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n; cin >> n;
    rep(i, n) cin >> x.at(i) >> y.at(i);
    vector<int> vec(n);
    rep(i, n) vec.at(i) = i;
    double dis_sum = 0;
    do{
        for(int i = 0; i < n-1; i++){
            dis_sum += distance(vec.at(i), vec.at(i+1));
        }
    }while(next_permutation(vec.begin(), vec.end()));
    int pattern = 1;
    for(int i = 1; i <= n; i++) pattern *= i;
    printf("%.10lf", dis_sum/pattern);
    return 0;
}
