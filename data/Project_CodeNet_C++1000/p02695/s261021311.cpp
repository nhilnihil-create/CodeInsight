// 154 B

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>

using namespace std;

int main(){
    int n, m, q;
    long long int sum=0, max=0;
    cin >> n >> m >> q;

    vector<long long int> a(n, 1);
    vector<vector<long long int>> v (q, vector<long long int>(4, 0));

    for(int i=0; i<q; i++){
        cin >> v.at(i).at(0) >> v.at(i).at(1) >> v.at(i).at(2) >> v.at(i).at(3);
    }

    while(true){
        for(int i=n-1; i>0; i--){
            if(a.at(i) > m){
                a.at(i-1)++;
            }
        }
        for(int i=1; i<n; i++){
            if(a.at(i) > m){
                a.at(i) = a.at(i-1);
            }
        }
        if(a.at(0) > m) break;

        sum = 0;
        for(auto buf: v){
            if( a.at(buf.at(1)-1) - a.at(buf.at(0)-1) == buf.at(2)){ sum += buf.at(3);}
        }
        if(sum > max) max = sum;

        a.at(n-1)++;
    }

    cout << max << endl;

    return 0;
}