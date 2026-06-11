#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N;

int main(){
    cin >> N;
    vector<pair<int,int>> point(N);
    for(int i=0; i<N; i++) cin >> point.at(i).first >> point.at(i).second;
    // vector<vector<double>> distan(N,vector<double>(N));
    double ans=0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            double dis = sqrt(pow(point.at(i).first-point.at(j).first,2)+pow(point.at(i).second-point.at(j).second,2));
            ans += dis;
        }
    }
    printf("%f\n",2*ans/N);
}