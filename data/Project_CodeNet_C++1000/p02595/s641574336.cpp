#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; int D; int count=0;
    int x; int y; 

    //ifstream myfile;
    //myfile.open("sample.txt");
    cin >> N >> D;

    double max_squared_distance = pow(D,2);
    map<pair<int,int>,double> m;
    
    while(N--){
        cin >> x >> y;
        if(abs(x) > D || abs(y)> D){
            continue;
        }
        pair<int,int> p = make_pair(x,y);
        if(m[p]){
            if(m[p] <= max_squared_distance){
                count++;
            }
            continue;
            
        }
        double squared_distance = pow(x,2) + pow(y,2);
        m[p] = squared_distance;
        if(squared_distance <= max_squared_distance){
            count++;
        }
    }
    cout << count;
    
    return 0;
}