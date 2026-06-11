#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    double dist=0;
    int count=0;
    vector<vector<double>> x(n, vector<double>(d));
    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            cin >> x.at(i).at(j);
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            for(int k=0; k<d; k++){
                dist+=pow(x.at(i).at(k)-x.at(j).at(k),2);
            }
            for(int k=1; k<201; k++){
                if(dist==k*k){
                    count++;
//                    cout << dist << endl;
                }
                if(dist<=k*k) break;
            }
            dist=0;
        }
    }
    cout << count << endl;
}