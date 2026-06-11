#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d; cin >> n >> d;
    vector<vector<double>> x(n, vector<double>(d));
    for(int i=0; i<n; i++)
        for(int j=0; j<d; j++)
            cin >> x[i][j];
    double distance = 0.0;
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            distance = 0.0;
            for(int k=0; k<d; k++){
                distance += pow(x[i][k]-x[j][k], 2);
            }
            distance = sqrt(distance);
            if(distance == ceil(distance))
                count++ ;
        }
    }
    cout << count << endl;
    return 0;
}