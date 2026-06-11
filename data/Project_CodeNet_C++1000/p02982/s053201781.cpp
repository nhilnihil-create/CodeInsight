#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int N, D, count = 0;
    double dist;
    std::cin >> N >> D;
    vector<vector<double>> points(N);
    vector<double> a_point(D);
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < D; j++){
            std::cin >> a_point[j];
        }
        points[i] = a_point;
    }
    //input終了
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            dist = 0.0;
            for(int d = 0; d < D; d++){
                dist = dist + (points[i][d] - points[j][d])*(points[i][d] - points[j][d]);
            } 
            dist = sqrtf(dist);

            //std::cout << dist << " " << floorf(dist) << "\n";
            if(dist == floorf(dist)){
                count++;
            }
        }
    }

    std::cout << count;

}